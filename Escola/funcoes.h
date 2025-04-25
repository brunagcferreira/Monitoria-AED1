typedef struct Aluno{
    int matricula;
    char nome[35];
    int *notas;
}Aluno;

typedef struct Turma{
    int id;
    int qntdAlunosNaTurma;
    Aluno **alunosMatriculados;
}Turma;

typedef struct Escola{
    int qntdTurmas;
    int qntdAlunos;
    Turma **todasAsTurmas;
    Aluno **todosAlunos;
}Escola;

Escola* criarEscola(){
    Escola *escola = malloc(sizeof(Escola));
    escola->qntdAlunos = 0;
    escola->qntdTurmas = 0;
    escola->todasAsTurmas = NULL;
    escola->todosAlunos = NULL;

    return escola;
}

void criarTurma(Escola *escola){
    Turma *turma = malloc(sizeof(Turma*));
    turma->id = 0;
    turma->qntdAlunosNaTurma = 0;
    turma->alunosMatriculados = NULL;
    printf("Digite o ID da turma que deseja cadastrar: ");
    scanf("%d", &turma->id);

    escola->qntdTurmas += 1;
    escola->todasAsTurmas = realloc(escola->todasAsTurmas, sizeof(Turma*)*escola->qntdTurmas);
    escola->todasAsTurmas[escola->qntdTurmas-1] = turma;
}

void criarAluno(Escola *escola){
    Aluno *aluno = malloc(sizeof(Aluno*));
    aluno->notas = NULL;

    printf("Digite o nome do aluno: ");
    scanf("%34[^\n]", aluno->nome);
    getchar();

    printf("Digite a matricula do anulo: ");
    scanf("%d", &aluno->matricula);
    getchar();

    escola->qntdAlunos += 1;
    escola->todosAlunos = realloc(escola->todosAlunos, sizeof(Aluno*)*escola->qntdAlunos);
    escola->todosAlunos[escola->qntdAlunos-1] = aluno;

}

int buscarAluno(Escola *escola, int matricula){
    int i = 0;
    for(i=0; i < escola->qntdAlunos; i++){
        if(escola->todosAlunos[i]->matricula == matricula){
            return i;
        }
    }
    return -1;
}

int buscarTurma(Escola *escola, int id){
    int i = 0;
    for(i=0; i < escola->qntdTurmas; i++){
        if(escola->todasAsTurmas[i]->id == id){
            return i;
        }
    }
    return -1;
}

void matricularAlunoEmTurma(Escola *escola){
    int alunoIdx, turmaIdx;
    
    do{
        printf("Digite a matricula do aluno: ");
        int matricula;
        scanf("%d", &matricula);
        getchar();
    
        alunoIdx = buscarAluno(escola, matricula);

        if(alunoIdx == -1){
            printf("aluno não matriculado");
        }

    }while (alunoIdx == -1);

    do{
        printf("Digite o ID da turma que deseja inserir o aluno: ");
        int id;
        scanf("%d", &id);
        getchar();

        turmaIdx = buscarTurma(escola, id);

        if (turmaIdx == -1){
            printf("turma não encontrada");
        }

    }while(turmaIdx == -1);

    Turma *turma = escola->todasAsTurmas[turmaIdx];
    Aluno *aluno = escola->todosAlunos[alunoIdx];
    turma->qntdAlunosNaTurma += 1;
    turma->alunosMatriculados = realloc(turma->alunosMatriculados, sizeof(Aluno*)*turma->qntdAlunosNaTurma);
    turma->alunosMatriculados[turma->qntdAlunosNaTurma-1] = aluno;    
}

void exibirTurmas(Escola *escola){
    int i;
    for(i=0; i < escola->qntdTurmas; i++){
        printf("TURMA: %d\n", escola->todasAsTurmas[i]->id);
    }
}

void exibirAlunos(Escola *escola){
    int i;
    for(i=0; i < escola->qntdAlunos; i++){
        printf("Aluno: %s. Matricula: %d\n", escola->todosAlunos[i]->nome, escola->todosAlunos[i]->matricula);
    }
}

void exibirAlunosDaTurma (Escola *escola){
    int i, id, idx;
    do{
        printf("Digite o ID da turma que deseja exibir: ");
        scanf("%d", &id);
        idx = buscarTurma(escola, id);

        if(idx == -1){
            printf("Turma não encontrada tente novamente");
        }

    }while(idx == -1);

    Turma *turma = escola->todasAsTurmas[idx];

    for(i = 0; i < turma->qntdAlunosNaTurma; i++){
        printf("Aluno: %s. Matricula: %d\n", turma->alunosMatriculados[i]->nome, turma->alunosMatriculados[i]->matricula);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
    char nome[50];
    int idade;
}Aluno;

void exibirAlunosSub14(Aluno *lista, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(lista[i].idade <= 14){
            printf("%s\n%d\n", lista[i].nome, lista[i].idade);
        }
    }
}

void exibirAlunosMais14(Aluno *lista, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(lista[i].idade > 14){
            printf("%s\n%d\n", lista[i].nome, lista[i].idade);
        }
    }
}

Aluno criarAluno(char nome[50], int idade){
    Aluno aluno;
    strcpy(aluno.nome, nome);
    aluno.idade = idade;
    return aluno;
}

int main(void){
    int qntd, i;
    scanf("%d", &qntd);
    getchar();
    Aluno *listaAlunos = malloc(sizeof(Aluno)*qntd);

    for(i=0; i<qntd; i++){
        char nome[50];
        int idade;

        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        scanf("%d", &idade);
        getchar();

        Aluno a = criarAluno(nome, idade);        
       
        listaAlunos[i] = a;
    }

    exibirAlunosSub14(listaAlunos, qntd);
    exibirAlunosMais14(listaAlunos, qntd);

    free(listaAlunos);
    
    return 0;
}
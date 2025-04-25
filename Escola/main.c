#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void){
    Escola *escola = criarEscola();
    int opcao;
    printf("\n==== MENU ====\n");
    printf("1. Criar aluno\n");
    printf("2. Criar turma\n");
    printf("3. Matricular aluno em turma\n");
    printf("4. Exibir todos os alunos\n");
    printf("5. Exibir todas as turmas\n");
    printf("6. Exibir alunos matriculados em uma turma\n");
    printf("99. Sair\n");
    do {
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                criarAluno(escola);
                break;
            case 2:
                criarTurma(escola);
                break;
            case 3:
                matricularAlunoEmTurma(escola);
                break;
            case 4:
                exibirAlunos(escola);
                break;
            case 5:
                exibirTurmas(escola);
                break;
            case 6:
                exibirAlunosDaTurma(escola);
                break;
            case 99:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 99);

    return 0;
}
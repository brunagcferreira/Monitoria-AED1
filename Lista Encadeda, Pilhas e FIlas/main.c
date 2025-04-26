#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

int main (void){

    No *lista = NULL;
    int opcao;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Inserir no começo\n");
        printf("2. Inserir no final\n");
        printf("3. Remover no começo\n");
        printf("4. Remover no final\n");
        printf("5. Exibir\n");
        printf("6. REmover no meio\n");
        printf("99. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                lista = inserir(lista, 1);
                break;
            case 2:
                lista = inserir(lista,2);
                break;
            case 3:
                lista = removerNoInicio(lista);
                break;
            case 4:
                lista = removerNoFim(lista);
                break;
            case 5:
                exibir(lista);
                break;
            case 6:
                printf("Digite um valor: ");
                int v;
                scanf("%d", &v);
                lista = removerNoMeio(lista, v);
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
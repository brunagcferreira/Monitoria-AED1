#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.c"

int main (void){

    No *lista = NULL;
    int opcao;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Inserir na fila\n");
        printf("2. Remover na fila\n");
        printf("3. Exibir fila\n");
        printf("99. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                lista = inserir(lista, 2);
                break;
            case 2:
                lista = removerNoInicio(lista);
                break;
            case 3:
                exibir(lista);
                break;
            case 99:
                printf("\nSaindo\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 99);
    

    return 0;
}
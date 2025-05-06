#include <stdio.h>
#include <stdlib.h>
#include "inserirOrdenado.c"

int main(void){
    int elemento = 0;
    int tamanho = 0;
    int *vet = malloc(sizeof(int));

    printf("Insira um elemento(ou digite 99 para sair): \n");
    scanf("%d", &elemento);
    while (elemento != 99){
        
        inserirOrdenado(&vet, &tamanho, elemento);
        exibir(vet, tamanho);
        printf("%d\n", tamanho);
        
        printf("Insira um elemento(ou digite 99 para sair): \n");
        scanf("%d", &elemento);
    }

    free(vet);

    return 0;
}
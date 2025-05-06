#include <stdio.h>
#include <stdlib.h>

void exibir(int *vetor, int tam){
    printf("\n");
    int i;
    for(i=0; i<tam; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

void inserirOrdenado(int **vet, int *tamanho, int elemento){
    if(*tamanho == 0){
        (*vet)[*tamanho] = elemento;
    }else{
        (*vet) = realloc((*vet), sizeof(int)*(*tamanho+1));
        int i = *tamanho-1;
    
        while (i >= 0 && elemento < (*vet)[i]){
            (*vet)[i+1] = (*vet)[i];
            i--;
        }
    
        (*vet)[i+1] = elemento;
    }

    (*tamanho)++;
}
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

void insertionSort(int *vet, int tamanho){
    int i, j, key;
    for(i = 1; i < tamanho; i++){
        key = vet[i];
        j = i-1;
        while (j >= 0 && key < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = key;
    }
}


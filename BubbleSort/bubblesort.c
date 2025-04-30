#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *vetor, int tam){

    int i, j;

    for(i=0; i<tam-1; i++){
        for(j=0; j<tam-i-1; j++){
            if(vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }

}

void bubblesortwithboolean (int *vetor, int tam){
    int j, troca;
    troca = 1;

    while(troca){
        troca = 0;
        for(j=0; j<tam-1; j++){
            if(vetor[j] > vetor[j+1]){
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                troca = 1;
            }
        }
    }
}

void exibir(int *vetor, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}
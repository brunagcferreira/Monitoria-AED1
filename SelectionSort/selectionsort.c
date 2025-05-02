#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int tam){
    int i, j, min, temp;
    for(i = 0; i < tam-1; i++){
        min = i;

        for(j = i+1; j < tam; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }

        temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;
    }

}

void exibir(int *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}
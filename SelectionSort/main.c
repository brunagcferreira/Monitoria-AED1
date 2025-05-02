#include <stdio.h>
#include <stdlib.h>
#include "selectionsort.c"

int main(void){
    int tamanho, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    for(i=0; i<tamanho; i++){
        printf("Digite o vetor: ");
        int temp;
        scanf("%d", &temp);
        vetor[i] = temp;
    }
    exibir(vetor, tamanho);
    selectionSort(vetor, tamanho);
    exibir(vetor, tamanho);
    return 0;
}
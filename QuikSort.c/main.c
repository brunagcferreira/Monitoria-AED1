#include <stdio.h>
#include <stdlib.h>
#include "quickSort.c"

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
    quickSort(vetor, 0, tamanho-1);
    exibir(vetor, tamanho);
    free(vetor);

    return 0;
}
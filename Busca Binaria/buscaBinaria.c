#include <stdio.h>
#include <stdlib.h>

int buscabinaria(int inicio, int fim, int *vet, int elemento){
    int meio = (inicio+fim)/2;
    int saida;

    if(inicio>fim){
        saida = -1;
    }else if(vet[meio]==elemento){
        saida = meio;
    }
    else if(elemento < vet[meio]){
        saida = buscabinaria(inicio, meio-1, vet, elemento);
    }else if(elemento > vet[meio]){
        saida = buscabinaria(meio+1, fim, vet, elemento);
    }
    return saida;
}
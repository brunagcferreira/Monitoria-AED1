#include <stdio.h>
#include <stdlib.h>
#include "buscaBinaria.c"

int main(void){
    int tam,i, elemento, busca;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int *vet = malloc(sizeof(int)*tam);

    for(i=0; i<tam; i++){
        vet[i] = i+1;
    }

    printf("Vetor de tamanho %d preenchido automáticamente em ordem crescente de 1 a %d\n", tam, tam);
    for(i=0; i<tam; i++){
        printf("%d\n", vet[i]);
    }

    do{
        printf("Digite o elemento que deseja buscar ou 99 para encerrar: ");
        scanf("%d", &elemento);
        busca = buscabinaria(0, tam, vet, elemento);
        if(busca == -1){
            printf("elemento não encontrado\n");
        }else{
            printf("elemento %d encontrado\n", vet[busca]);
        }

    }while(elemento != 99);

    return 0;
}
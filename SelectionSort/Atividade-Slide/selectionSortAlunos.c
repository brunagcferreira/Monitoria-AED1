#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int id;
    float altura;
    int idade;
}Aluno;

Aluno criarALuno(int id, float altura, int idade){
    Aluno aluno;
    aluno.id = id;
    aluno.altura = altura;
    aluno.idade = idade;
    return aluno;
}

void ordenarPelaAltura(Aluno *lista, int tam){
    int i, j, min;
    for(i=0; i<tam-1; i++){
        min = i;
        for(j=i+1; j<tam; j++){
            if(lista[j].altura < lista[min].altura){
                min = j;
            }
        }
        Aluno temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
    }
}

void exibir(Aluno *lista, int tam){
    printf("\n");
    int i;
    for(i=0; i<tam; i++){
        printf("[%f] ", lista[i].altura);
    }
    printf("\n");
}
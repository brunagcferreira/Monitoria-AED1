#include <stdio.h>
#include <stdlib.h>
#include "selectionSortAlunos.c"

int main(void){
    int qntd, i, id, idade;
    float altura;
    
    printf("Digite a quantidade de alunos que deseja cadastrar: ");
    scanf("%d", &qntd);
    Aluno *listaAlunos = malloc(sizeof(Aluno)*qntd);

    for(i=0; i<qntd; i++){
        printf("Id: ");
        scanf("%d", &id);
        printf("Altura: ");
        scanf("%f", &altura);
        printf("Idade: ");
        scanf("%d", &idade);

        listaAlunos[i] = criarALuno(id,altura,idade);
    }
    
    exibir(listaAlunos, qntd);
    ordenarPelaAltura(listaAlunos, qntd);
    exibir(listaAlunos, qntd);


    
    return 0;
}
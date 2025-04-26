#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

No* inserirNoInicio(No *no, No *novo){
    if(no == NULL){
        return novo;
    }
    novo->prox = no;
    return novo;
}

No* inserirNoFim(No *no, No *novo){
    if(no == NULL){
        return novo;
    }
    no->prox = inserirNoFim(no->prox, novo);
    return no;
}

No* removerNoInicio(No *no){
    if(no == NULL){
        return NULL;
    }
    No *aux = no->prox;
    free(no);
    return aux;
}

No* removerNoFim(No *no){
    if(no == NULL){
        return NULL;
    }
    else if(no->prox == NULL){
        free(no);
        return NULL;
    }
    no->prox = removerNoFim(no->prox);
    return no;
}

No* removerNoMeio(No *no, int i){
    if (no == NULL){
        return NULL;
    }
    else if(no->valor == i){
        no = removerNoInicio(no);
        return no;
    }
    no->prox = removerNoMeio(no->prox, i);
    return no;
}

void exibir(No *no){
    if(no != NULL){
        printf("%d ", no->valor);
        exibir(no->prox);
    }
}

No* criarNo(int i){
    No *no = malloc(sizeof(No));
    no->valor = i;
    no->prox = NULL;
    return no;
}

No* inserir (No *no, int opc){
    int i;
    printf("valor: ");
    scanf("%d", &i);
    No *novo = criarNo(i);

    if(opc == 1){
        no = inserirNoInicio(no, novo);

    }else if( opc == 2){
        no = inserirNoFim(no, novo);
    }

    return no;
}
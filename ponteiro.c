#include <stdio.h>
#include <stdlib.h>

void troca (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void conversor (int minutos, int *hora, int *min){
    int a = minutos/60;
    *min = minutos-(a*60);
    *hora = a;
}

int main(void){
    int a, b, c;
    a = 5;
    b = 9;
    int *p, *q;
    int **r; //ponteiro para ponteiro

    p = &a;
    q = &b;
    r  = &p; //r recebe o endereço de memória de p
    printf("p = %p\n", p); //exibe o endereço de memória de A, exibe o conteúdo para onde p está apontando
    printf("&a = %p\n", &a); //exibe o endereço de memória de A
    printf("q = %p\n", q); //exibe o endereço de memória de B, exibe o conteúdo para onde q está apontando
    printf("r = %p\n", r); //exibe o endereço de memória de p, exibe o cnteúdo para onde r aponta
    printf("*r = %p\n", *r); //exibe o conteúdo de p, ou seja o endereço de memória de A
    printf("**r = %d\n", **r); //exipe o conteúdo para o qual p aponta, ou seja A = 5

    c = *p + *q;
    printf("%d\n", c);
    c += **r;
    printf("%d\n", c);

    troca (&a, &b);
    printf("A = %d \nB = %d\n", a, b);

    int min = 265;
    int h=0;
    int m=0;
    conversor(min, &h, &m);
    printf("horas = %d\nminutos = %d\n", h, m);

    return 0;
}
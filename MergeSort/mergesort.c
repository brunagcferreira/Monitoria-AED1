#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int l, int m, int r){
    //delaração das variáveis de controle
    int i, j, k;
    //n1 = tamanho do sub-array esquerdo (L - left)
    int n1 = m - l + 1;
    //n2 = tamanho do sub-array direito (R - Right)
    int n2 = r - m;
    //delaração dos sub-arrays
    int L[n1];
    int R[n2];
    //inicialização dos valores dos sub-arrays
    for(i=0; i<n1; i++){
        L[i] = arr[i+l];
    }
    for(j=0; j<n2; j++){
        R[j] = arr[j+m+1];
    }

    //mesclar os sub-arrays de maneira ordenada de volta para o array "arr"
    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2){
        arr[k] = R[j];
        j++;
        k++;
    } 
}

void mergeSort(int *arr, int l, int r){
    if(l<r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void exibir(int *arr, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition (int *arr, int low, int high){
    int i, j, pivot;

    pivot = arr[high];
    i = low-1;

    for(j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int *arr, int low, int high){
    if(low < high){
        int idx_pivot = partition(arr, low, high);

        quickSort(arr, low, idx_pivot-1);
        quickSort(arr, idx_pivot+1, high);
    }
}

void exibir(int *arr, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}
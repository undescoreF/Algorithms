#include <stdio.h>
#include <stdlib.h>

// 
void swap(int tab[], int index_1, int index_2) {
    int tps = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = tps;
}

// Fonction de partitionnement
int partition(int tab[], int low, int high) {
    int pivot = tab[high]; 
    int i = low; 

    for (int j = low; j < high; j++) {
        if (tab[j] <= pivot) {
            swap(tab, i, j); 
            i++;
        }
    }
    swap(tab, i, high);
    return i; 
}

void quicksort(int tab[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(tab, low, high);
        quicksort(tab, low, pivot_index - 1); // left
        quicksort(tab, pivot_index + 1, high); // right
    }
}


int main() {
    int arr[1000];
    for(int i=0;i<1000;i++){
        arr[i]=rand()%30000;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
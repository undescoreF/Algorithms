#include <stdio.h>

void bubbleSort(int array[], int size){
    int swapped;
    for(int i=0; i<size -1; i++){
        swapped = 0;
        for(int j=0; j<size-i-1; j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0) break;
    }
}


int main() {
    int array[] = {5, 2, 9, 1, 5, 6};
    //array's length
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, size);

    for(int i =0; i<size;i++){
        printf("%d ", array[i]);
  }
    
}
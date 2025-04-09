#include <stdio.h>
#include <math.h>

int jumpSearch(int tab[], int size, int target){
    int start = 0;
    int jp = sqrt(size);
    while(start<size){
        if(tab[start]==target) return start;
        if(tab[start]>target) break;
        start+=jp;
    }
    int left = fmax(0, start - jp);
    int right = fmin(start, size - 1); 

    for(int i=left; i<=right; i++){
        if(tab[i]==target){
            return i;
        }
    }
    return -1;

}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7,7, 8, 9,11,13};
    int length = sizeof(arr) / sizeof(arr[0]);
    int n;

    printf("Enter a number to search: ");
    scanf("%d", &n);

    int index = jumpSearch(arr, length, n);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
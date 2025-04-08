#include <stdio.h>

int linear_search(int tab[], int size,int element){
    for(int i=0; i<size; i++){
        if(tab[i]==element) return i;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 7, 2, 9, 5, 1, 8, 4, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int n;

    printf("Enter a number to search: ");
    scanf("%d", &n);

    int index = linear_search(arr, length, n);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
#include <stdio.h>
int binary_search(int tab[], int size, int element) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
       
        if (tab[mid] == element) {
            return mid;
        }
        else if (tab[mid] < element) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;  
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int n;

    printf("Enter a number to search: ");
    scanf("%d", &n);

    int index = binary_search(arr, length, n);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

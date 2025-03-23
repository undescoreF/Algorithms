#include <stdio.h>

//base sort or radix sort
void radixSort(int tab[], int n) {
    int b[10][n]; // Buckets for digits 0-9
    int count[10] = {0}; // Count of elements in each bucket
    int max = tab[0];
    int div = 1;

    // Find the maximum element to determine the number of digits
    for (int i = 0; i < n; i++) {
        if (tab[i] > max)
            max = tab[i];
    }

    // Process each digit place
    while (max / div > 0) {
        // Distribute elements into buckets based on current digit
        for (int i = 0; i < n; i++) {
            int digit = (tab[i] / div) % 10;
            b[digit][count[digit]] = tab[i];
            count[digit]++;
        }

        
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                tab[index] = b[i][j];
                index++;
            }
            count[i] = 0; 
        }

        div *= 10; 
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
} 

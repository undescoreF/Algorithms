#include <stdio.h>

void selectionSort(double tab[], int size) {
    for (int i = 0; i < size - 1; i++) {
        
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (tab[j] < tab[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            double temp = tab[i];
            tab[i] = tab[minIndex];
            tab[minIndex] = temp;
        }
    }
}

int main() {
    double tab[] = {64, 25, 12, 22, 11};
    int size = sizeof(tab) / sizeof(tab[0]);
    // 
    selectionSort(tab, size);
    for (int i = 0; i < size; i++) printf("%.2f  ", tab[i]);
    return 0;

}
#include <stdio.h>

void insertion(double tab[], int size) {
    for (int i = 1; i < size; i++) {
        double tps = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > tps) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = tps;
    }
}

int main() {
    double table[] = {5, 3, 8, 4};  
    int size = sizeof(table) / sizeof(table[0]);  
    
    insertion(table, size);
    
    for (int i = 0; i < size; i++) {
        printf("%.1f ", table[i]);
    }

    return 0;
}

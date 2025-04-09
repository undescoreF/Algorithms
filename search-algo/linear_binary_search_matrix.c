#include <stdio.h>

int linear_search_matrix(int n,int m, int tab[n][m], int element){
 //linear search in matrix
 for(int i=0;i<n;i++){
    for(int j=0; j<m;j++){
        if(tab[i][j]==element) {
            printf("Element found at line %d, column %d\n", i, j);
            return 0;
        }
    }
 }
   return -1;
}
int binary_search_matrix(int n,int m, int tab[n][m], int element) {
    int left = 0;                         
    int right = n * m - 1;         
    
    // binary search in matrix
    while (left <= right) {
        int mid = left + (right - left) / 2;  
        
        int row = mid / m;
        int col = mid % m;
        
        if (tab[row][col] == element) {    
            return mid;                       
        }
        else if (tab[row][col] < element) {
            left = mid + 1;                   
        }
        else {
            right = mid - 1;                  
        }
    }
    
    return -1;  
}

int main() {
    int n = 3;
    int m = 3;

    int tab[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int element;
    printf("Enter a number to search: ");
    scanf("%d", &element);

    // Recherche linéaire
    printf("\n--- Linear Search ---\n");
    int found_linear = linear_search_matrix(n, m, tab, element);
    if (found_linear == -1) {
        printf("Element not found\n");
    }

    // Recherche binaire
    printf("\n--- Binary Search ---\n");
    int index = binary_search_matrix(n, m, tab, element);
    if (index != -1) {
        int row = index / m;
        int col = index % m;
        printf("Element found at row %d, column %d\n", row, col);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

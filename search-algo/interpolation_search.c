
#include <stdio.h>

int interpolation_search(int tab[], int size, int element) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        
         if (tab[right] == tab[left]) {
            if (tab[left] == element) return left;
            return -1;
        }
        
        int pos = left + (element-tab[left])*(right-left)/(tab[right]-tab[left]);
        
        if (pos < left) pos = left;
        if (pos > right) pos = right;
        
        if(tab[pos]==element) return pos;
        
        else if(tab[pos]<element){
            left = pos+1;
        }else{
            right=pos-1;
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

    int index = interpolation_search(arr, length, n);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
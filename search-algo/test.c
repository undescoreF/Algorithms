#include <stdio.h>

int line_compare(int size, int tab[], int tab2[]){
    for(int i=0; i<size; i++){
        if(tab[i]!=tab2[i]) return 0;
    }
    return 1;
}

int search(int line, int col, int matrix[line][col], int tab[]){
    for(int i =0; i<line;i++){
       if( line_compare(col,matrix[0],tab)) return i;
       
    }
    return -1;
 }
    
int main()
{
   int tab[3] = {2,1,4};
   int matrix[4][3] = {
        {1, 2, 3},
        {1, 4, 5},
        {2, 0, 0},
        {2, 1, 4}
    };
   int result = search(4,3,matrix[4][3],tab);
   printf(result!=-1 ? "Element found at index %d" : "not found", result);
    return 0;
}
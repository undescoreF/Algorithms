#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search_time.h"
int main()
{
    //time variable 
    clock_t start, end;
    double cpu_time_used;
    //table initialization
    int tab[10000];
    int element[10000];
    for(int i=0;i<10000;i++){
        tab[i]= rand()%300000;
        element[i] = rand()%300000;
    }
    //quick sort 
    int n = sizeof(tab) / sizeof(tab[0]);
    quicksort(tab, 0, n - 1);

    //binary_search.....
    start = clock();
    for(int i=0; i<10000;i++){
        binary_search(tab, n, element[i]);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary search time : %f\n", cpu_time_used);

    //interpolation_search
    start = clock();
    for(int i=0; i<10000;i++){
        interpolation_search(tab,n, element[i]);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Interpolation search time : %f\n", cpu_time_used);

    //linear search
    start = clock();
    for(int i=0; i<10000;i++){
        linear_search(tab,n, element[i]);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linear search time : %f", cpu_time_used);
    return 0;
}
#ifndef ALGO
#define ALGO

//linear search
int linear_search(int tab[], int size,int element){
    for(int i=0; i<size; i++){
        if(tab[i]==element) return i;
    }
    return -1;
}
//quick Sorting 
void swap(int tab[], int index_1, int index_2) {
    int tps = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = tps;
}

// Fonction de partitionnement
int partition(int tab[], int low, int high) {
    int pivot = tab[high]; 
    int i = low; 

    for (int j = low; j < high; j++) {
        if (tab[j] <= pivot) {
            swap(tab, i, j); 
            i++;
        }
    }
    swap(tab, i, high);
    return i; 
}

void quicksort(int tab[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(tab, low, high);
        quicksort(tab, low, pivot_index - 1); // left
        quicksort(tab, pivot_index + 1, high); // right
    }
}

// binaray search 
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

//interpolation_search
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

#endif
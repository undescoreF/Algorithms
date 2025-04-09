#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_USERS 1000

typedef struct {
    int id;
    char first_name[50];
    char email[100];
    char gender[10];
} User;

void swap(User tab[], int index_1, int index_2) {
    User tps = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = tps;
}

//sort by name 
int partition(User tab[], int low, int high) {
    User pivot = tab[high]; 
    int i = low; 
    for (int j = low; j < high; j++) {
        if (strcmp(tab[j].first_name, pivot.first_name) < 0) {
            swap(tab, i, j); 
            i++;
        }
    }
    swap(tab, i, high);
    return i; 
}

void quicksort_by_name(User tab[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(tab, low, high);
        quicksort_by_name(tab, low, pivot_index - 1); // left
        quicksort_by_name(tab, pivot_index + 1, high); // right
    }
}

int read_csv(const char *filename, User users[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error while opening file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    
    // Ignorer l'en-tête
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return -1;
    }

    while (fgets(line, sizeof(line), file) && count < MAX_USERS) {
        line[strcspn(line, "\n")] = 0;
        
        char *token = strtok(line, ",");
        if (!token) continue;
        users[count].id = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strncpy(users[count].first_name, token, sizeof(users[count].first_name) - 1);

        token = strtok(NULL, ",");
        if (!token) continue;
        strncpy(users[count].email, token, sizeof(users[count].email) - 1);

        token = strtok(NULL, ",");
        if (!token) continue;
        strncpy(users[count].gender, token, sizeof(users[count].gender) - 1);

        count++;
    }

    fclose(file);
    return count;
}

int write_csv(const char *filename, User users[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error while opening file");
        return -1;
    }

    fprintf(file, "id,first_name,email,gender\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s\n", 
                users[i].id, 
                users[i].first_name, 
                users[i].email, 
                users[i].gender);
    }

    fclose(file);
    return 0;
}

int main() {
    User records[MAX_USERS];
    int record_count = read_csv("random_user.csv", records);
    
    if (record_count <= 0) {
        printf("Error while reading the file\n");
        return 1;
    }

    printf("Starting name sorting...\n"); 
    clock_t start = clock();
    
    quicksort_by_name(records, 0, record_count - 1);
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    if (write_csv("random_user_sorted_by_name.csv", records, record_count)) {
        printf("Error while writing the sorted file\n");
        return 1;
    }

    printf("Sorting completed in %.5f seconds\n", time_spent);
    printf("First 10 sorted names:\n");
    for (int i = 0; i < 10 && i < record_count; i++) {
        printf("%s\n", records[i].first_name);
    }

    return 0;
}
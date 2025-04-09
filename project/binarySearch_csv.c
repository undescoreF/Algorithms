#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_LINE_LENGTH 1024
#define MAX_USERS 1000

typedef struct 
{
    int id;
    char first_name[50];
    char email[100];
    char gender[10];
} User;
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


int binary_search(User tab[], int size, char name[50]) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(tab[mid].first_name,name)==0) {
            return mid;
        }
        else if (strcmp(tab[mid].first_name,name)<0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;  
}
int main() {
    User records[MAX_USERS];
    char name[50];
    int record_count = read_csv("random_user_sorted_by_name.csv", records);
    
    if (record_count <= 0) {
        printf("Error while reading the file\n");
        return 1;
    }
    printf("Enter a name : ");
    scanf("%s",name);
    printf("Starting name sorting...\n"); 
    clock_t start = clock();
    

    int result = binary_search(records,record_count - 1,name);
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Searching completed in %.30f seconds\n", time_spent);
    if(result!=-1){

        printf("element found at index %d\n\n", result);
        printf("user_id : %d\n", records[result].id);
        printf("first_name : %s\nemail : %s\ngender : %s", records[result].first_name,records[result].email,records[result].gender);
       

    }else {
        printf("User not found");
    }

    return 0;
}

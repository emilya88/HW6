#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *file1, *file2;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_number = 1;


    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        perror("Error opening file2.txt");
        fclose(file1);
        return 1;
    }

    while (fgets(line1, sizeof(line1), file1) != NULL &&
           fgets(line2, sizeof(line2), file2) != NULL) {
        if (strcmp(line1, line2) != 0) {
          
            printf("Difference found at line %d:\n", line_number);
            printf("file1: %s", line1);
            printf("file2: %s", line2);
            break;
        }
        line_number++;
    }

 
    if (fgets(line1, sizeof(line1), file1) != NULL || fgets(line2, sizeof(line2), file2) != NULL) {
        printf("Files differ at line %d:\n", line_number);
        if (fgets(line1, sizeof(line1), file1) != NULL) {
            printf("file1: %s", line1);
        } else {
            printf("file1: End of file reached.\n");
        }
        if (fgets(line2, sizeof(line2), file2) != NULL) {
            printf("file2: %s", line2);
        } else {
            printf("file2: End of file reached.\n");
        }
    } else {
        printf("The files are identical.\n");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}

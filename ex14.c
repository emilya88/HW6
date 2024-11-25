#include <stdio.h>
#include <stdlib.h>

void sortArray(int *arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int *arr;
    int n;

    printf("enter the number of elements ");
    scanf("%d", &n);

    
    arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed \n");
        return -1;  
    }

    
    printf("Input %d number of elements :\n", n+1);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", arr + i);
    }

    sortArray(arr, n);

    printf("\nThe elements in the array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("element - %d : %d\n", i + 1, *(arr + i));
    }

    free(arr);

    return 0;
}

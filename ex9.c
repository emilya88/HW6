#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("enter the number of elements :");
    scanf("%d", &n);

    int *arr= (int*)malloc(n*sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    
    printf("Input %d number of elements in the array:\n", n+1);
    for (int i = 0; i < n; i++) {
        printf("element  %d is ", i);
        scanf("%d", &arr[i]);
    }

    int largest=arr[0];
    for (int i = 0; i < n; i++) {
       if(largest<arr[i]){
        largest=arr[i];
       }
    }

    printf("the lrgest element is %d", largest);

    free(arr);

    return 0;
}
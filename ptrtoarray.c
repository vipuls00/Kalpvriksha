#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr;

    ptr = arr;

    printf("First element: %d\n", *ptr);  
    printf("Second element: %d\n", *(ptr + 1));  
    printf("Third element: %d\n", *(ptr + 2));  

    *(ptr + 1) = 10;  

    printf("Modified array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}

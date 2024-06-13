#include <stdlib.h>
#include <stdio.h>

void swap(int **arr, int i1, int j1, int i2, int j2) {
    int temp = arr[i1][j1];
    arr[i1][j1] = arr[i2][j2];
    arr[i2][j2] = temp;
}

void swapp(int **arr, int rows, int cols) {
    swap(arr, 0, 0, rows - 1, cols - 1); 
    swap(arr, 0, cols - 1, rows - 1, 0); 
}

int main() {
    int rows, cols;
    int **arr;

    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    swapp(arr, rows, cols);

    printf("Matrix after swapping:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

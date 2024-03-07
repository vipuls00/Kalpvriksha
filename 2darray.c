#include <stdio.h>

int main() {
    int x, y;

    printf("Enterrows and columns ");
    scanf("%d %d", &x, &y);

    int arr[x][y];
    printf("Enter elements ");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("2D array\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}


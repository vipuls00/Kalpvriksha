#include <stdio.h>

int main() {
    int size;

    printf("Enter size");
    scanf("%d", &size);

    int arr[size];
  
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

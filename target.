#include <stdio.h>

void findPairs(int arr[], int size, int target) {     
    for (int i = 0; i < size - 1; i++) {         
        for (int j = i + 1; j < size; j++) {             
            if (arr[i] + arr[j] == target) {               
                printf("(%d, %d)\n", arr[i], arr[j]);            
            }        
        }   
    }
}

int main() {
    int target = 5;
    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    findPairs(arr, size, target);
    return 0;
}

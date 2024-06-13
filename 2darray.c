// #include <stdio.h>

// int main() {
//     int x, y;

//     printf("Enter rows and columns");
//     scanf("%d %d", &x, &y);

//     int arr[x][y];
//     printf("Enter elements ");
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             scanf("%d", &arr[i][j]);
//         }
//     }
//     printf("2D array\n");
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < y; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

#include <stdlib.h>
#include <stdio.h>
 int main(){
    int rows, cols;
    char str[100];
    scanf("%[^\n]%*c",str);
    printf("%s",str);
    scanf("%d %d", &rows, &cols);
    int **arr;
    arr = (int**)malloc(rows*sizeof(int*));
    for(int i =0; i < rows; i++){
        arr[i] = (int*)malloc(cols*sizeof(int));
    }
    for(int i = 0; i < rows; i++){
        for(int j =0; j < cols; j++){
            scanf("%d",&arr[i][j]);
        }
    }
       for(int i = 0; i < rows; i++){
        for(int j =0; j < cols; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
 }
 int main(){
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    char str[100];
    scanf("%[^\n]%*c",str);
    int **arr;
    arr = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < cols; i++)
    {
        arr[i] = (int*)malloc(cols* sizeof(int));
    }
    
    return 0;
 }
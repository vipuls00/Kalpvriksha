#include <stdio.h>

int main() {
    int num = 10;
    char ch = 'A';
    float pi = 1.2;

    void *ptr;
  
    ptr = &num;
    printf("Value of num: %d\n", *(int *)ptr);

    ptr = &ch;
    printf("Value of ch: %c\n", *(char *)ptr);

    ptr = &pi;
    printf("Value of pi: %f\n", *(float *)ptr);

    return 0;
}

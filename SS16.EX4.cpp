#include <stdio.h>
void printArray(int *arr, int length){
    for (int i=1; i<length; i++) {
        printf("%d\t", i, *(arr + i));
    }
}
int main(){
    int array[5] = {1, 2, 3, 4, 5};
    int length = 6;
    printArray(array, length);
    return 0;
}

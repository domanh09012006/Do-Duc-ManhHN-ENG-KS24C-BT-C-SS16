#include <stdio.h>
int sum(int a, int b, int *result){
    *result = a + b;
}
int main(){
    int x = 5;
    int y = 10, Result;
    sum(x, y, &Result);
    printf("Tong la: %d", Result);
	return 0;
}

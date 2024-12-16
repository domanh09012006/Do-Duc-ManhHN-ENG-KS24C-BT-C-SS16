#include <stdio.h>
void doiCho(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int x = 5;
    int y = 10;
    doiCho(&x, &y);
    printf("Gia tri cua 2 so sau khi doi cho la: %d, %d", x, y);
	return 0;
}

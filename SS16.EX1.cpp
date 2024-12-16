#include<stdio.h>
int main(){
	int num1 = 10;
	int *numb1 = &num1;
	//In ra gia tri
	printf("Gia tri cua bien la: %d", num1);
	printf("Gia tri cua bien la: %d\n", *numb1);
	//In ra dia chi
	printf("Dia chi cua bien la: %d\n", &num1);
	printf("Dia chi cuabien la: %d", numb1);
}

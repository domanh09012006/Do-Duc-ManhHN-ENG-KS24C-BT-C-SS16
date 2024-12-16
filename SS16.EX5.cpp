#include<stdio.h>
void add(int *arr, int length, int pos, int val){
	if(pos>=0 && pos<length){
		arr[pos] = val;
	}else{
		printf("Vi tri khong hop le");
	}
}
int main(){
	int array[] = {1,2,3,4,5};
	int pos=3;
	int val=1;
	int length=sizeof(array)/sizeof(int);
	printf("Mang chua them la: \n");
	for(int i=0; i<length; i++){
		printf("%d\t", array[i]);
	}
	printf("Mang sau khi them: \n");
	add(array, length, pos, val);
	for(int i=0; i<length; i++){
		printf("%d\t", array[i]);
	}
}

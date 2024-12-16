#include<stdio.h>
int Find(int *arr, int length, int find){
	for(int i=0; i<length; i++){
		if(*(arr+i) == find){
			printf("Gia tri %d duoc tim thay tai vi tri %d" ,find, i);
			return i;
		}
	}
}
int main(){
	int array[] = {1,2,3,4,5};
	int find=4;
	int length=sizeof(array)/sizeof(int);
	Find(array, length, find);
	
}

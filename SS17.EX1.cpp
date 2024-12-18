#include<stdio.h>
#include<stdlib.h>

int main(){
	int *arrPtr;
	int n, choice, a=0, b=0, length=0, sum=0, max=0;
	while(a<1){
		printf("\n---MENU---\n");
		printf("1.Nhap kich thuoc va cac phan tu cho mang\n");
		printf("2.In ra mang\n");
		printf("3.Tinh do dai mang\n");
		printf("4.Tinh tong cac phan tu\n");
		printf("5.In ra phan tu lon nhat\n");
		printf("6.Thoat\n");
		printf("Lua chon cua ban:\n ");
		scanf("%d", &choice);
		switch(choice){
			case 1://Nhap ki thuoc va cac phan tu cho mang
				while(b<1){
					printf("Nhap kich thuoc cho mang: ");
					scanf("%d", &n);
					if(n>0){
						arrPtr = (int*)malloc(n*sizeof(int));
						b++;
					}else{
						printf("Kich thuoc khong hop le!");
					}
				}
				printf("Nhap tung phan tu cho mang: ");
				for(int i=0; i<n; i++){
					printf("arr[%d] = ", i+1);
					scanf("%d", arrPtr + i);
				}
				
			break;
			case 2://In ra mang
				printf("Cac phan tu co trong mang la: \n");
				for(int i=0; i<n; i++){
					printf("%d\t", *(arrPtr+i));
				}
			break;
			case 3://Tinh do dai mang
				length = sizeof(arrPtr)/sizeof(int);
				printf("Mang co do dai la: %d", length);
			break;
			case 4://Tinh tong cac phan tu
				printf("Tong cac phan tu cua mang la: ");
				for(int i=0; i<n; i++){
					sum += arrPtr[i];
				}
				printf("%d", sum);
			break;
			case 5://In ra phan tu lon nhat
				printf("Phan tu lon nhat trong mang la:");
				for(int i=0; i<n; i++){
					if(arrPtr[i]>max){
						max = arrPtr[i];
					}
				}
				printf("%d", max);
			break;
			case 6://Thoat
				printf("Thoat!");
				a++;
				return 0;
			break;
			default: 
				printf("Khong co lua chon nay!");
			break;
			
		}
	}
}


#include <stdio.h>
#include <stdlib.h>

int kiemTraSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void hoanDoi(int* a, int* b) {
    int tam = *a;
    *a = *b;
    *b = tam;
}

void sapXepTangDan(int* array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                hoanDoi(&array[i], &array[j]);
            }
        }
    }
}

void sapXepGiamDan(int* array, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] < array[j]) {
                hoanDoi(&array[i], &array[j]);
            }
        }
    }
}

void inSoChan(int* array, int n) {
    printf("Cac so chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

void inSoNguyenTo(int* array, int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (kiemTraSoNguyenTo(array[i])) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int* array, int n) {
    for (int i = 0; i < n / 2; i++) {
        hoanDoi(&array[i], &array[n - 1 - i]);
    }
}

void timKiemPhanTu(int* array, int n, int phanTu) {
    for (int i = 0; i < n; i++) {
        if (array[i] == phanTu) {
            printf("Phan tu %d ton tai trong mang tai vi tri %d.\n", phanTu, i);
            return;
        }
    }
    printf("Phan tu %d khong ton tai trong mang.\n", phanTu);
}

int main() {
    int* array = NULL;
    int n, choice, phanTu;
    
    while (1) {
        printf("\n---MENU---\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   1. Tang dan\n");
        printf("   2. Giam dan\n");
        printf("6. Nhap vao mot phan tu va tim kiem trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap vao so phan tu trong mang: ");
                scanf("%d", &n);
                array = (int*)malloc(n * sizeof(int));
                printf("Nhap vao cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &array[i]);
                }
                break;
            case 2:
                if (array != NULL) {
                    inSoChan(array, n);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 3:
                if (array != NULL) {
                    inSoNguyenTo(array, n);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 4:
                if (array != NULL) {
                    daoNguocMang(array, n);
                    printf("Mang sau khi dao nguoc: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 5:
                printf("Lua chon sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon cua ban: ");
                int luaChonSapXep;
                scanf("%d", &luaChonSapXep);
                if (array != NULL) {
                    if (luaChonSapXep == 1) {
                        sapXepTangDan(array, n);
                        printf("Mang sau khi sap xep tang dan: ");
                    } else if (luaChonSapXep == 2) {
                        sapXepGiamDan(array, n);
                        printf("Mang sau khi sap xep giam dan: ");
                    }
                    for (int i = 0; i < n; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 6:
                if (array != NULL) {
                    printf("Nhap vao phan tu can tim: ");
                    scanf("%d", &phanTu);
                    timKiemPhanTu(array, n, phanTu);
                } else {
                    printf("Chua nhap mang!\n");
                }
                break;
            case 7:
                printf("Thoat!\n");
                if (array != NULL) {
                    free(array);
                }
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}


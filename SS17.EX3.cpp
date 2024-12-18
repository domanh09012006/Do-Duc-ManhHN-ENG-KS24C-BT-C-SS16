#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string = NULL;
    char *addString = NULL;  // Thay d?i tên bi?n t? tempString thành addString
    int choice;
    int len, lenAddString; // Thay size_t b?ng int
    int add = 0; // Thay d?i tên bi?n inWord thành add

    while (1) {
        printf("\n---MENU---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: // Nhap vao chuoi
                string = (char *)malloc(100 * sizeof(char));
                printf("Nhap vao chuoi: ");
                fgets(string, 100, stdin);
                break;
            case 2: // In ra chuoi dao nguoc
                if (string != NULL) {
                    int length = strlen(string);
                    for (int i = 0; i < length / 2; i++) {
                        char temp = string[i];
                        string[i] = string[length - 1 - i];
                        string[length - 1 - i] = temp;
                    }
                    printf("Chuoi dao nguoc la: %s\n", string);
                    for (int i = 0; i < length / 2; i++) {
                        char temp = string[i];
                        string[i] = string[length - 1 - i];
                        string[length - 1 - i] = temp;
                    }
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;

            case 3: // Dem so luong tu trong chuoi
                if (string != NULL) {
                    int count = 0;
                    add = 0;
                    while (*string != '\0') {
                        if (*string == ' ' || *string == '\n' || *string == '\t') {
                            add = 0;
                        } else if (add == 0) {
                            add = 1;
                            count++;
                        }
                        string++;
                    }
                    printf("So luong tu trong chuoi: %d\n", count);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 4: // Nhap vao chuoi khac, so sanh chuoi
                if (string != NULL) {
                    addString = (char *)malloc(100 * sizeof(char)); // Thay tempString thành addString
                    if (addString == NULL) {
                        printf("Khong du bo nho\n");
                        return 1;
                    }
                    printf("Nhap vao chuoi khac: ");
                    fgets(addString, 100, stdin);
                    lenAddString = strlen(addString);
                    if (addString[lenAddString - 1] == '\n') {
                        addString[lenAddString - 1] = '\0';
                    }
                    if (strlen(addString) < strlen(string)) {
                        printf("Chuoi ban dau dai hon chuoi nhap vao\n");
                    } else if (strlen(addString) > strlen(string)) {
                        printf("Chuoi ban dau ngan hon chuoi nhap vao\n");
                    } else {
                        printf("Hai chuoi co do dai bang nhau\n");
                    }
                    free(addString);
                } else {
                    printf("Chua nhap chuoi ban dau!\n");
                }
                break;
            case 5: // In hoa tat ca chu cai trong chuoi
                if (string != NULL) {
                    for (int i = 0; string[i] != '\0'; i++) {
                        if (string[i] >= 'a' && string[i] <= 'z') {
                            string[i] = string[i] - 'a' + 'A';
                        }
                    }
                    printf("Chuoi sau khi in hoa: %s\n", string);
                } else {
                    printf("Chua nhap chuoi!\n");
                }
                break;
            case 6: // Nhap vao chuoi khac va them vao chuoi ban dau
                if (string != NULL) {
                    addString = (char *)malloc(100 * sizeof(char)); // Thay tempString thành addString
                    if (addString == NULL) {
                        printf("Khong du bo nho\n");
                        return 1;
                    }
                    printf("Nhap vao chuoi khac de them: ");
                    fgets(addString, 100, stdin);
                    lenAddString = strlen(addString);
                    if (addString[lenAddString - 1] == '\n') {
                        addString[lenAddString - 1] = '\0';
                    }
                    string = (char *)realloc(string, (strlen(string) + strlen(addString) + 1) * sizeof(char));
                    strcat(string, addString);
                    printf("Chuoi sau khi them: %s\n", string);
                    free(addString);
                } else {
                    printf("Chua nhap chuoi ban dau!\n");
                }
                break;
            case 7: // Thot
                printf("Thoat!\n");
                if (string != NULL) {
                    free(string);
                }
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *string;
    int choice, a = 0, length;
    int indexChucai = 0, indexNumber = 0, indexCharacter = 0;
    while (a < 1) {
        printf("\n---MENU---\n");
        printf("1. Nhap kich thuoc va cac phan tu cho chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai\n");
        printf("4. Dem so luong chu so\n");
        printf("5. Dem so luong ki tu dac biet\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                string = (char *)malloc(100 * sizeof(char));
                printf("Nhap vao chuoi: ");
                fgets(string, 100, stdin);
            break;
            case 2:
                printf("Chuoi ki tu vua nhap la: %s\n", string);
            break;
            case 3:
                indexChucai = 0;
                for (char *ptr=string; *ptr !='\0'; ptr++) {
                    if ((*ptr >='a' && *ptr<='z') || (*ptr>='A' && *ptr<='Z')) {
                        indexChucai++;
                    }
                }
                printf("So luong chu cai: %d\n", indexChucai);
            break;
            case 4:
                indexNumber = 0;
                for (char *ptr=string; *ptr !='\0'; ptr++) {
                    if (*ptr>='0' && *ptr<='9') {
                        indexNumber++;
                    }
                }
                printf("So luong chu so: %d\n", indexNumber);
                break;

            case 5:
                indexCharacter = 0;
                for (char *ptr=string; *ptr !='\0'; ptr++) {
                    if (!(*ptr>='0' && *ptr<='9') && !(*ptr>='a' && *ptr<='z') && !(*ptr>='A' && *ptr<='Z') && *ptr !=' ') {
                        indexCharacter++;
                    }
                }
                printf("So luong ki tu dac biet: %d\n", indexCharacter);
                break;

            case 6:
                printf("Thoat!\n");
                a++;
                if (string != NULL) {
                    free(string);
                }
                return 0;

            default:
                printf("Khong co lua chon nay!\n");
                break;
        }
    }
}


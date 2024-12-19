#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Ham nhap chuoi
void nhapChuoi(char* chuoi, int kichThuoc) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, kichThuoc, stdin);
    size_t len = strlen(chuoi);
    if (chuoi[len - 1] == '\n') {
        chuoi[len - 1] = '\0';
    }
}
// Ham in chuoi
void inChuoi(char* chuoi) {
    printf("Chuoi vua nhap: %s\n", chuoi);
}
// Ham dem so luong chu cai trong chuoi
int demChuCai(char* chuoi) {
    int dem = 0;
    while (*chuoi) {
        if ((*chuoi >= 'A' && *chuoi <= 'Z') || (*chuoi >= 'a' && *chuoi <= 'z')) {
            dem++;
        }
        chuoi++;
    }
    return dem;
}
// Ham dem so luong chu so trong chuoi
int demChuSo(char* chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (*chuoi >= '0' && *chuoi <= '9') {
            dem++;
        }
        chuoi++;
    }
    return dem;
}
// Ham dem ky tu dac biet trong chuoi
int demKyTuDacBiet(char* chuoi) {
    int dem = 0;
    while (*chuoi) {
        if (!((*chuoi >= 'A' && *chuoi <= 'Z') || (*chuoi >= 'a' && *chuoi <= 'z') || (*chuoi >= '0' && *chuoi <= '9') || *chuoi == ' ')) {
            dem++;
        }
        chuoi++;
    }
    return dem;
}
int main() {
    int choice;
    char chuoi[100];
    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                nhapChuoi(chuoi, sizeof(chuoi));
                break;
            case 2:
                inChuoi(chuoi);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demChuCai(chuoi));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demChuSo(chuoi));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(chuoi));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 6);
    return 0;
}


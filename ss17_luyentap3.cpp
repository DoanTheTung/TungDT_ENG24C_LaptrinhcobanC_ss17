#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Ham nhap chuoi
void nhapChuoi(char* chuoi, int kichThuoc) {
    printf("Nhap vao chuoi: ");
    fgets(chuoi, kichThuoc, stdin);
    size_t len = strlen(chuoi);
    if (len > 0 && chuoi[len - 1] == '\n') {
        chuoi[len - 1] = '\0';
    }
}
// Ham in chuoi dao nguoc
void inDaoNguocChuoi(char* chuoi) {
    int len = strlen(chuoi);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", chuoi[i]);
    }
    printf("\n");
}
// Ham dem so tu trong chuoi
int demSoTu(char* chuoi) {
    int soTu = 0;
    int trongTu = 0;
    while (*chuoi) {
        if (*chuoi != ' ' && !trongTu) {
            trongTu = 1;
            soTu++;
        } else if (*chuoi == ' ') {
            trongTu = 0;
        }
        chuoi++;
    }
    return soTu;
}
// Ham so sanh do dai chuoi
void soSanhChuoi(char* chuoi1, char* chuoi2) {
    int len1 = strlen(chuoi1);
    int len2 = strlen(chuoi2);
    if (len1 > len2) {
        printf("Chuoi ban dau dai hon chuoi moi.\n");
    } else if (len1 < len2) {
        printf("Chuoi ban dau ngan hon chuoi moi.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}
// ham in hoa tat ca chu cai trong chuoi
void inHoaChuoi(char* chuoi) {
    while (*chuoi) {
        *chuoi = toupper(*chuoi);
        chuoi++;
    }
}
// Ham noi 2 chuoi
void noiChuoi(char* chuoi1, char* chuoi2, int kichThuoc) {
    strncat(chuoi1, chuoi2, kichThuoc - strlen(chuoi1) - 1);
}
int main() {
    int choice;
    char chuoi1[100] = ""; // Kh?i t?o chu?i r?ng
    char chuoi2[100];
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                nhapChuoi(chuoi1, sizeof(chuoi1));
                break;
            case 2:
                inDaoNguocChuoi(chuoi1);
                break;
            case 3:
                printf("So luong tu trong chuoi: %d\n", demSoTu(chuoi1));
                break;
            case 4:
                printf("Nhap vao chuoi khac: ");
                nhapChuoi(chuoi2, sizeof(chuoi2));
                soSanhChuoi(chuoi1, chuoi2);
                break;
            case 5:
                inHoaChuoi(chuoi1);
                printf("Chuoi sau khi in hoa: %s\n", chuoi1);
                break;
            case 6:
                printf("Nhap vao chuoi khac: ");
                nhapChuoi(chuoi2, sizeof(chuoi2));
                noiChuoi(chuoi1, chuoi2, sizeof(chuoi1));
                printf("Chuoi sau khi noi: %s\n", chuoi1);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 7);
    return 0;
}

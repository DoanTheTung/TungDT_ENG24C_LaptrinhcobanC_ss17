#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Ham kiem tra so nguyent to
bool laSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// ham nhap phan tu va tang kich thuoc mang
void nhapMang(int* mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
// Ham in ra cac phan tu la so chan
void inSoChan(int* mang, int kichThuoc) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] % 2 == 0) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}
// Ham in ra phan tu la so nguyen to
void inSoNguyenTo(int* mang, int kichThuoc) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < kichThuoc; i++) {
        if (laSoNguyenTo(mang[i])) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}
// Ham dao nguoc mang
void daoNguocMang(int* mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc / 2; i++) {
        int temp = mang[i];
        mang[i] = mang[kichThuoc - i - 1];
        mang[kichThuoc - i - 1] = temp;
    }
}
// Ham sap xep phan tu theo thu tu tang dan
void sapXepTangDan(int* mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc - 1; i++) {
        for (int j = i + 1; j < kichThuoc; j++) {
            if (mang[i] > mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}
// Ham sap xep phan tu theo thu tu giam dan
void sapXepGiamDan(int* mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc - 1; i++) {
        for (int j = i + 1; j < kichThuoc; j++) {
            if (mang[i] < mang[j]) {
                int temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
            }
        }
    }
}
// Hm tim kiem phan tu trong mang
int timKiemPhanTu(int* mang, int kichThuoc, int giaTri) {
    for (int i = 0; i < kichThuoc; i++) {
        if (mang[i] == giaTri) {
            return i;
        }
    }
    return -1;
}
int main() {
    int choice;
    int* mang = NULL;
    int kichThuoc = 0;
    do {
        printf("MENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("6. Nhap vao mot phan tu va tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (mang != NULL) {
                    free(mang);
                }
                printf("Nhap vao so phan tu: ");
                scanf("%d", &kichThuoc);
                mang = (int*)malloc(kichThuoc * sizeof(int));
                nhapMang(mang, kichThuoc);
                break;
            case 2:
                if (mang != NULL) {
                    inSoChan(mang, kichThuoc);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 3:
                if (mang != NULL) {
                    inSoNguyenTo(mang, kichThuoc);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 4:
                if (mang != NULL) {
                    daoNguocMang(mang, kichThuoc);
                    printf("Mang sau khi dao nguoc: ");
                    for (int i = 0; i < kichThuoc; i++) {
                        printf("%d ", mang[i]);
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 5:
                if (mang != NULL) {
                    int luaChonSapXep;
                    printf("1. Tang dan\n");
                    printf("2. Giam dan\n");
                    printf("Lua chon cua ban: ");
                    scanf("%d", &luaChonSapXep);
                    if (luaChonSapXep == 1) {
                        sapXepTangDan(mang, kichThuoc);
                    } else if (luaChonSapXep == 2) {
                        sapXepGiamDan(mang, kichThuoc);
                    } else {
                        printf("Lua chon khong hop le!\n");
                    }
                    printf("Mang sau khi sap xep: ");
                    for (int i = 0; i < kichThuoc; i++) {
                        printf("%d ", mang[i]);
                    }
                    printf("\n");
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 6:
                if (mang != NULL) {
                    int giaTriCanTim;
                    printf("Nhap vao phan tu can tim: ");
                    scanf("%d", &giaTriCanTim);
                    int viTri = timKiemPhanTu(mang, kichThuoc, giaTriCanTim);
                    if (viTri != -1) {
                        printf("Phan tu %d xuat hien tai vi tri %d trong mang.\n", giaTriCanTim, viTri);
                    } else {
                        printf("Phan tu %d khong xuat hien trong mang.\n", giaTriCanTim);
                    }
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 7);
    if (mang != NULL) {
        free(mang);
    }
    return 0;
}

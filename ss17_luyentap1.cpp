#include <stdio.h>
#include <stdlib.h>
// Ham nhap so phan tu va tung phan tu trong mang
void nhapMang(int* mang, int kichThuoc) {
    for (int i = 0; i < kichThuoc; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}
// Ham hien thi phan tu trong mang
void hienThiMang(int* mang, int kichThuoc) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < kichThuoc; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}
// Ham tinh tong phan tu trong mang
int tinhTong(int* mang, int kichThuoc) {
    int tong = 0;
    for (int i = 0; i < kichThuoc; i++) {
        tong += mang[i];
    }
    return tong;
}
// Ham tim phan tu lon nhat trong mang
int phanTuLonNhat(int* mang, int kichThuoc) {
    int max = mang[0];
    for (int i = 1; i < kichThuoc; i++) {
        if (mang[i] > max) {
            max = mang[i];
        }
    }
    return max;
}
int main() {
    int choice;
    int* mang = NULL;
    int kichThuoc = 0;
    do {
        printf("MENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
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
                    hienThiMang(mang, kichThuoc);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 3:
                printf("Do dai mang: %d\n", kichThuoc);
                break;
            case 4:
                if (mang != NULL) {
                    int tong = tinhTong(mang, kichThuoc);
                    printf("Tong cac phan tu trong mang: %d\n", tong);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 5:
                if (mang != NULL) {
                    int max = phanTuLonNhat(mang, kichThuoc);
                    printf("Phan tu lon nhat trong mang: %d\n", max);
                } else {
                    printf("Mang chua duoc khoi tao!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 6);
    if (mang != NULL) {
        free(mang);
    }
    return 0;
}

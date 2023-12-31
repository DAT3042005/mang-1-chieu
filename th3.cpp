#include <stdio.h>
#include <stdlib.h>

// H�m nh?p m?ng m?t chi?u
void nhapMang(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

// H�m xu?t m?ng m?t chi?u
void xuatMang(int *arr, int n) {
    printf("Mang vua nhap:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

// H�m t�m gi� tr? l?n nh?t trong m?ng
int timMax(int *arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

// H�m t�nh t�ch c�c ph?n t? trong m?ng
long long tinhTich(int *arr, int n) {
    long long tich = 1;
    for (int i = 0; i < n; ++i) {
        tich *= *(arr + i);
    }
    return tich;
}

// H�m ki?m tra s? nguy�n t?
int laSoNguyenTo(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// H�m d?m v� t�nh t?ng c�c s? nguy�n t? trong m?ng
void demVaTinhTongSoNguyenTo(int *arr, int n, int *count, int *sum) {
    *count = 0;
    *sum = 0;
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(*(arr + i))) {
            (*count)++;
            (*sum) += *(arr + i);
        }
    }
}

// H�m t�m v? tr� c�c ph?n t? c� gi� tr? b?ng x
void timViTriX(int *arr, int n, int x) {
    int found = 0;
    printf("Vi tri cua %d trong mang: ", x);
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) == x) {
            printf("%d\t", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong ton tai");
    }
    printf("\n");
}

// H�m s?p x?p m?ng tang d?n
void sapXepTangDan(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

// H�m ch�n gi� tr? x v�o m?ng
void chenGiaTri(int *arr, int *n, int x, int viTri) {
    (*n)++;
    arr = (int *)realloc(arr, (*n) * sizeof(int));

    for (int i = *n - 1; i > viTri; --i) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + viTri) = x;
}

// H�m x�a gi� tr? k kh?i m?ng
void xoaGiaTri(int *arr, int *n, int k) {
    int i, j;
    for (i = 0; i < *n; ++i) {
        if (*(arr + i) == k) {
            for (j = i; j < *n - 1; ++j) {
                *(arr + j) = *(arr + j + 1);
            }
            (*n)--;
            i--;
        }
    }
    arr = (int *)realloc(arr, (*n) * sizeof(int));
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    nhapMang(arr, n);
    xuatMang(arr, n);

    // Y�u c?u 4
    int max = timMax(arr, n);
    printf("Gia tri lon nhat trong mang: %d\n", max);

    // Y�u c?u 5
    long long tich = tinhTich(arr, n);
    printf("Tich cac phan tu trong mang: %lld\n", tich);

    // Y�u c?u 6
    int countNguyenTo, sumNguyenTo;
    demVaTinhTongSoNguyenTo(arr, n, &countNguyenTo, &sumNguyenTo);
    printf("So luong so nguyen to trong mang: %d\n", countNguyenTo);
    printf("Tong cac so nguyen to trong mang: %d\n", sumNguyenTo);

    // Y�u c?u 7
    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);
    timViTriX(arr, n, x);

    // Y�u c?u 8
    sapXepTangDan(arr, n);
    printf("Mang sau khi sap xep tang dan:\n");
    xuatMang(arr, n);

    // Y�u c?u 9
    int giaTriChen, viTriChen;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &giaTriChen);
    printf("Nhap vi tri can chen (tu 1 den %d): ", n + 1);
    scanf("%d", &viTriChen);
    chenGiaTri(arr, &n, giaTriChen, viTriChen - 1);
    printf("Mang sau khi chen gia tri:\n");
    xuatMang(arr, n);

    // Y�u c?u 10
    int giaTriXoa;
    printf("Nhap gia tri can xoa: ");
        scanf("%d", &giaTriXoa);
    xoaGiaTri(arr, &n, giaTriXoa);
    printf("Mang sau khi xoa gia tri:\n");
    xuatMang(arr, n);

    // Gi?i ph�ng b? nh?
    free(arr);

    return 0;
}

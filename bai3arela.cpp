#include <stdio.h>
#include <math.h>

bool snt(int n) {
    if(n == 1) return false;
    if(n < 4) return true;
    for(int i = 2 ; i <= sqrt(n) ; ++i)
        if(n % i == 0) return false;
    return true;
}

int slsnt(int n , int check[]) {
    int count = 0;
    for(int i = 2 ; i <= n ; ++i) {
        if(check[i]) continue;
        for(int j = 2 * i ; j <= n ; j+=i)
            check[j] = i;
    }
     for(int i = 2 ; i <= n; ++i)
        if(check[i] == 0) count++;
    return count;
}

int timSoNguyenToGanNhat(int N) {
    int soNguyenToGanNhat = 0;
    int khoangCach = N;
    for (int i = N - 1; i > 1; --i) {
        int j;
        for (j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i)) {
            if (abs(N - i) < khoangCach) {
                khoangCach = abs(N - i);
                soNguyenToGanNhat = i;
            }
        }
    }
    return soNguyenToGanNhat;
}
int main(){
	int n;
	int sum = 0;
	printf ("Nhap so nguyen duong n = ");
	scanf("%d", &n);
	int check[n + 1];
    for(int i = 2 ; i <= n ; ++i)
        check[i] = 0;
    printf("So luong so nguyen to tu 1 den %d la: %d\n" , n , slsnt(n,check));
    printf("Cac so nguyen to tu 1 den %d la : "  , n);
    for(int i = 2 ; i <= n; ++i)
        if(check[i] == 0) printf("%d " , i);
    printf ("\n");
    printf("Tong cua cac so nguyen to tu 1 den %d la: " , n);
    for (int i = 2; i <=n ; ++i){
    	if(check[i] == 0) sum = sum + i;
	}
	printf ("%d", sum);
	int soNguyenToGanNhat = timSoNguyenToGanNhat(n);
    while (soNguyenToGanNhat % 3 != 0) {
        soNguyenToGanNhat = timSoNguyenToGanNhat(soNguyenToGanNhat - 1);
    }
	printf("\n");
    printf("So nguyen to chia het cho 3 va gan N nhat la: %d\n", soNguyenToGanNhat);
    return 0;
}
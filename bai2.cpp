#include<iostream>
#include<math.h>
using namespace std;

void resetMang(int a[], int n){
	for(int i = 0; i <= n; i++){
		a[i] = 0;
	}
}

void MangUocSo(int a[], int n){
	resetMang(a, n);
	for(int i = 1; i <= sqrt(n); i++){
		if(n % i == 0){
			a[i] = 1;
			a[n / i] = 1;
		}
	}
}

void uocSoCuaN(int a[],int n){
	resetMang(a, n);
	int i = 2;
	int save = n;
	while(true){
		if(n % i == 0){
			n = n / i;
			a[i]++;
		}else {
			i++;
		}
		if(n == 1){
			break;
		}
	}
	int tong = 1;
	for(int i = 0; i < save; i++){
		if(a[i] != 0){
			tong = tong * (a[i] + 1);
		}
	}
	cout << tong;
}


void eratos(int a[], int n){
	resetMang(a, n);
	for(int i = 2; i < n; i++){
		if(a[i] == 1){
			continue;
		}else{
			for(int j = 2; j < n; j++){
				a[i * j] = 1;
				if(i * j > n){
					break;
				}
			}
		}
	}
}

void eratosSoNhoHonn(int a[], int n){
	int soLuong = 0;
	int tong = 0;
	eratos(a, n);
	cout << "\nTat ca cac so nguyen to la uoc cua " << n << " la :";
	for(int i = 2; i <= n; i++){
		if(a[i] == 0 && n % i == 0){
			cout << i << "  ";
			soLuong++;
			tong += i;
		}
	}
	cout << "\nTong so luong la : " << soLuong;
	cout << "\nTong tat ca cac so do la : " << tong;
}

int TongUocSo(int n){
	int tong = 0;
	for(int i = 1; i < n; i++){
		if(n % i == 0){
			tong += i;
		}
	}
	return tong;
}

void SoHoanHao(int n){
	for(int i = 2; i <= n; i++){
		if(i == TongUocSo(i)){
			cout << i << " ";
		}
	}
}

int main(){
	int n;
	cin >> n;
	int a[300000];
	cout << "So luong uoc so cua " << n << " la :";
	uocSoCuaN(a ,n);
	eratosSoNhoHonn(a, n);
	cout << "\nSo Hoan hao : ";
	SoHoanHao(n);
}

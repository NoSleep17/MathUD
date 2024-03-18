#include<iostream>
#include<math.h>
using namespace std;
int chinese(int a[],int  b[] ,int n){
    int c[n];
    int d[n];
    int M=1;
    for(int i=0;i < n ;i++){
        M *= b[i];
    }
    
    for(int i=0;i < n ;i++){
        c[i]= M / b[i];
    }
    for(int i=0; i< n;i++){
        for(int k=0;k < 100000;k++){
            if(((b[i]*k+1)%c[i])==0){
                d[i] =((b[i]*k+1)/c[i]);
                break;
            }
        }
    }
    int temp=0;
    for( int i=0 ;i < n; i++){
        temp += a[i]*c[i]*d[i];
    }
    int kq = temp % M;
    cout << "x =" << kq << "+ k*"<< M << endl;
    return kq;
}

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int countprime(int n){
    int temp =0;
    for(int i=2 ;i < n;i++){
        if(gcd(1, i)==1){
            temp ++;
        }
    }
    return temp;
}
int main(){
    int n;
    cout << "ChineseEquations:"<< endl << "nhap so luong phuong trinh:"<< endl;
    cin >>n;

    int a[100], b[100];
    for(int i=0 ;i < n ;i++){
        cout << "Nhap he so phuong trinh thu"<< i+1<<  endl;
        cin>> a[i];
        cin >> b[i];
    }
    chinese(a, b,n);
    return 0;
}

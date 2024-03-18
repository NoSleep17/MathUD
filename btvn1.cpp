#include<iostream>
#include<math.h>
int checksonguyento(int n){
    if(n < 2){
        return 0;
    }
    int count = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count == 0){
        return n;
    }else{
        return 0;
    }
}
bool checksohoanhao(int a){
    int sum = 0;
    for(int i=1; i<=a/2 ;i++){ 
        if(a%i==0) 
            sum+=i;
    }
    if(sum==a){ 
        return true;
    } 
    return false; 
}
int countsonguyento(int a){
    return a/(log(a));
}

using namespace std;
int main (){
    int n;
    cout << "nhap n:" << endl;
    cin >> n;
    int *a = new int[10000];
    int *b = new int[10000];
    int *c = new int[10000];
    for(int i=0; i < sqrt(n); i++){
        a[i]= checksonguyento(i);
    }
    cout << n << "=";
    for(int i=2; i < sqrt(n); i++){
        if(a[i] != 0){
            int count =0;
            int temp =n;
            while(temp % a[i] == 0){
                count ++;
                temp = temp /a[i];
            }
            if(count > 0 && a[i]==2){
                cout << a[i]<< "^"<< count;
                b[i]= count;
                c[i]= a[i];
            }else if(count > 0){
                cout <<"*"<< a[i]<< "^"<< count;
                b[i]= count;
                c[i]= a[i];
            }
        }
    }
    cout << endl << "So luong uoc so cua n: ";
    int temp1 =1;
    for(int i=2; i < sqrt(n); i++){
        if(b[i] != 0){
            temp1 *= (b[i]+1);
        }
    }
    cout << temp1 << endl;
    int temp2 =1;
    cout << "tong cac uoc so: ";
    for(int i=2; i < sqrt(n); i++){
        if(b[i] != 0){
            temp2 *= ((pow(c[i],b[i]+1)-1)/(c[i]-1));
        }
    }
    cout << temp2 << endl;
    cout << "tich cua cac uoc so:" << pow(n, temp1 / 2) << endl;
    delete[] a;
    if(checksohoanhao(n)){
        cout << n <<" La so hoan hao"<< endl;
    }else{
        cout << n <<" Khong phai so hoan hao"<< endl;
    }
    cout << "mat do so nguyen to tu 1 den " << n << ":"<< countsonguyento(n);
    
}
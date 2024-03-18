#include<iostream>
#include<math.h>
using namespace std;
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
long tongsonguyento(int a[], int n){
    int temp =0;
    for(int i=0; i < n; i++){
        if(a[i] != 0){
            temp += a[i];
        }
    }
    return temp;
}
void songuyentogann(int n){
    int a =n;
    int x = checksonguyento(n);
    if (x!=0){
        cout << x;
    }
    int y = 0;
    int c;
    while(checksonguyento(n) ==0){
        n++;
        y++;
        c = n;
    }
    int z= 0;
    int d;
    while(checksonguyento(a) ==0){
        a--;
        z++;
        d = a;
    }
    if(y==z){
        cout << c <<" "<< d<< endl;
    }else if(y<z){
        cout << c<< endl;
    }else{
        cout << d << endl;
    }

}
int main(){
    int n;
    cin >> n;
    int *a = new int[100000];
    for(int i;i <= n; i++){
        a[i]=checksonguyento(i);
        if(a[i] != 0){
            cout << a[i] << " ";
        }
    }
    cout << endl <<"tong cac so nguyen to nho hon "<< n<<":" << tongsonguyento(a , n);
    cout << endl << "so nguyen to gan :";
    songuyentogann(n);
    delete[] a;
}
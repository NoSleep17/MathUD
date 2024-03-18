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
void countuocso(int n){
    int *a = new int[10000];
    int *b = new int[10000];
    int *c = new int[10000];
    for(int i=0; i < sqrt(n); i++){
        a[i]= checksonguyento(i);
    }
    cout << n << "=";
    for(int i=2; i < sqrt(n); i++){
        if(a[i] != 0){
            int count = 0;
            int temp = n;
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
    int count=0;
    for(int i=1;i<=n ; i++){
        if(n%i==0 && checksonguyento(i)){
            cout << i << " ";
            count ++;
        }
    }
    cout << endl << "trong "<< temp1 << " uoc so cua "<< n<<" co "<< count << " la so nguyen to";
}
int main(){
    int n; 
    cin >>n;
    countuocso(n);
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,p,q,r;
	cin >> a >> b >> c;
     p = a+b;
     q = a+c;
     r = b+c;
    if(p>=q){
        if(q >= r){
            cout << r;
        }else{
            cout << q;
        }
    }else{
        if(p >= r){
            cout << r;
        }else{
            cout << p;
        }
    }
}
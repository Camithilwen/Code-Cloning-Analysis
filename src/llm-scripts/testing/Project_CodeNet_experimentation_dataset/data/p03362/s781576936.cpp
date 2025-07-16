#include <bits/stdc++.h>
using namespace std;
int k = 55555;
int a[55555]={};
int main(){
    int n;
    cin >> n;
    for(int i=2;i<=k;i++){
        for(int j=i;j<=k;j+=i) a[j]++;
    }
    for(int i=2;i<=k;i++){
        if(a[i]==1){
            if(i%5==2&&n>0){
                cout << i << ' ';
                n--;
            }
        } 
    }
    cout << endl;
}
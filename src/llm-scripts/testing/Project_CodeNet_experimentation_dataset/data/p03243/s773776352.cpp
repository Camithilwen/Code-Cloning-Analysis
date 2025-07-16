#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int k = 111;
    for(int i = 1; i < 10; i++){
        if(k >= n){
            cout << k << endl;
            return 0;
        }
        k += 111;
    }
}
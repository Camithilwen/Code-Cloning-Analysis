#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a, b;
    cin >> a >> b;
    int sum = 1;
    rep(i,22){
        if(sum >= b){
            cout << i << endl;
            return 0;
        }
        sum--;
        sum += a;
    }
}
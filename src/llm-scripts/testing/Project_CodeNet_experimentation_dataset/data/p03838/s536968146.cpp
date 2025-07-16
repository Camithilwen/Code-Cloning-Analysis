#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x,y;
    cin >> x >> y;

    ll ans = 0;

    if (x * y > 0){
        if (x <= y){
            ans = y-x;
        }
        else{
            ans = x-y+2;
        }
    }
    else if (x * y == 0){
        if (x == 0){
            if (y >= 0){
                ans = y;
            }
            else{
                ans = abs(y)+1;
            }
        }
        else{
            if (x < 0){
                ans = abs(x);
            }
            else{
                ans = x+1;
            }
        }
    }
    else{
        if (abs(x) >= abs(y)){
            ans = abs(x)-abs(y)+1;
        }
        else{
            ans = abs(y)-abs(x)+1;
        }
    }
    
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll a, b; cin >> a >> b;

    if(a == 0){
        if(b < 0) cout << abs(b) + 1 << endl;
        else cout << abs(b) << endl;
    }else if(b == 0){
        if(a < 0) cout << abs(a) << endl;
        else cout << abs(a) + 1 << endl;
    }else if(0 < a && 0 < b){
        if(a < b){
            cout << b - a << endl;
        }else{
            cout << abs(b - a) + 2 << endl;
        }
    }else if(a < 0 && b < 0){
        if(abs(a) < abs(b)){
            cout << abs(b) - abs(a) + 2 << endl;
        }else{
            cout << abs(a) - abs(b) << endl;
        }
    }else if(a < 0 && 0 < b){
        if(abs(a) < b){
            cout << b - abs(a) + 1 << endl;
        }else{
            cout << abs(a) - b + 1 << endl;
        }
    }else if(0 < a && b < 0){
        if(a < abs(b)){
            cout << abs(b) - a + 1 << endl;
        }else{
            cout << a - abs(b) + 1 << endl;
        }
    }

    return 0;
}

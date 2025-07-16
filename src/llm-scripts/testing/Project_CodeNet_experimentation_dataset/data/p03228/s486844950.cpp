#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    rep(i, k) {
        if ( i & 1 ) {
            if ( b & 1 ) {
                --b;
            }
            a += b / 2;
            b /= 2;
        } 
        else {
            if ( a & 1 ) {
                --a;
            }
            b += a / 2;
            a /= 2;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n; cin >> n;
    vector<ll> a(n); cin >> a;
    vector<ll> b(n, 0);
    ll m = 0;
    for(ll i = n-1; i >= 0; --i){
        if((i+1)*2 > n){
            b[i] = a[i];
        }else{
            ll sum = 0;
            for(ll j = i; j < n; j += (i+1)){
                sum += b[j];
            }
            if(sum%2 == 0 && a[i] == 1) b[i] = 1;
            if(sum%2 == 1 && a[i] == 0) b[i] = 1;
        }
        m += b[i];
    }
    cout << m << endl;
    rep(i, n){
        if(m == 0) continue;
        if(i > 0 && b[i-1]) cout << " ";
        if(b[i]) cout << i+1;
    }
    return 0;
}
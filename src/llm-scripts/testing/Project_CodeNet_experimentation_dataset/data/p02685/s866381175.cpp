#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define MOD 998244353

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

class mint{
    typedef long long ll;
public:
    mint(ll a){
        _val = a%_mod;
    }
    mint(){
        _val=0;
    }
    explicit operator ll() {return _val;}
    ll _val;
    static const ll _mod = MOD;
};

mint operator*(mint mi, mint i){
    return mint(mi._val * i._val);
}
mint operator+(mint mi, mint i){
    return mint(mi._val + i._val);
}
mint operator/(mint mi, mint i){
    ll div = modpow(i._val,mi._mod-2,mi._mod);
    return mint(mi._val*div);
}



int main(){
    /*
    mint a(8960);
    mint b = a+3;
    cout << b._val << endl;
    b=a+6;
    cout << b._val << endl;
    b=a*5;
    cout << b._val <<endl;
    b=7*a;
    cout << b._val <<endl;
    b=a/2/1;
    cout << (ll)b<<endl;
    */
    
    ll n,m,k;
    cin >> n >> m >> k;
    vector<mint> kj(n), MM(n);
    kj[0] = mint(1);
    MM[0] = mint(1);
    rep(i,n-1){
        kj[i+1] = kj[i] * (i+1);
        MM[i+1] = MM[i] * (m-1);
        //cout << i+1 << " kj[i+1]: "<< kj[i+1]._val <<" MM[i+1]: "<< MM[i+1]._val<<endl;
    }

    mint sum(0);
    rep(i,k+1){
        mint tmp;
        tmp= tmp+kj[n-1]*m*MM[n-1-i];
        tmp= tmp/kj[n-1-i]/kj[i];
        sum = sum+tmp;
    }
    cout<<sum._val<<endl;

    return 0;
}

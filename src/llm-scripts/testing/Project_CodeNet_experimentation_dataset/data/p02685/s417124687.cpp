#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

const ll p = 998244353;

ll powmod(ll a, ll b){
    if(b==0) return 1;
    if(b%2==1) return (a*powmod(a,b-1)) % p;
    else{
        ll x = powmod(a,b/2);
        return (x*x) % p;
    }
}

ll combinemod(ll a, ll b){
    ll x=1,y=1;
    for(int i=1;i<=b;i++){
        y = (y*i)%p;
    }
    for(int i=a-b+1;i<=a;i++){
        x = (x*i)%p;
    }

    return (x * powmod(y,p-2)) % p;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<ll> dp1(k+1), dp2(k+1);
    dp1.at(0) = m * powmod(m-1,n-1) % p;
    dp2.at(0) = 1;
    rep(i,k){
        dp1.at(i+1) = m*powmod(m-1,n-1-(i+1)) % p;
        dp2.at(i+1) = (dp2.at(i) * (n-i-1) % p * powmod(i+1,p-2)) % p;
    }

    ll tot = 0;
    rep(i,k+1){
        tot += dp1.at(i) * dp2.at(i) % p;
        tot %= p;
    }

    cout << tot << endl;
    return 0;
}
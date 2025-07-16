#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;
ll modadd(ll a,ll b,ll mod=MOD){
    return (a%mod+b%mod)%mod;
}

ll modsub(ll a,ll b,ll mod=MOD){
    a%=mod;
    b%=mod;
    if(a>=b) return a-b;
    else return mod-b+a;
}

ll modmul(ll a,ll b,ll mod=MOD){
    return ((a%mod)*(b%mod))%mod;
}

ll modpow(ll a, ll n,ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll moddiv(ll a,ll b,ll mod=MOD) {
    return modmul(a, modpow(b, mod-2));
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,m;
    cin>>n>>m;
    vll x(n),y(m);
    for(ll i=0;i<n;i++)cin>>x[i];
    for(ll j=0;j<m;j++)cin>>y[j];
    
    sort(ALL(x));sort(ALL(y));
    
    ll a=0;
    for(ll i=0;i<n;i++){
        a=modadd(a,modmul(x[i],i-(n-1-i)));
    }
    
    ll b=0;
    for(ll i=0;i<m;i++){
        b=modadd(b,modmul(y[i],i-(m-1-i)));
    }
    
    cout<<modmul(a,b)<<endl;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

ll rep_pow(ll a, ll b){//繰り返し2乗法
    if(b==0) return 1;
    else if(b%2==0){
        ll memo = rep_pow(a, b/2);
        return memo*memo%mod;
    }else{
        return rep_pow(a, b-1)*a%mod;
    }
}

ll nCr(ll n, ll r){//mod逆元使ったnCr
    ll ret=1;
    rep(i,r){
        ret *= n-i;//分子
        ret %= mod;
        ret *=rep_pow(r-i, mod-2);//mod逆元によりr!で割ると同値
        ret %= mod;
    }
    return ret;
}
ll gcd(ll a, ll b){ if(b==0) return a; return gcd(b, a%b);}

int counter(int x){
    if(x==0) return 0;
    return counter(x>>1)+(x&1);
}


int main(){
    fast_io

    int n,k;
    cin>>n>>k;
    int ans=n-k+1;

    cout<<ans<<endl;
    return 0;
}
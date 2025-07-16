#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200 + 10, M = 100000 + 10;
const int mod = 1e9 + 7;
void add(ll &x,ll y){
    x += y;
    if(x>=mod) x -= mod;
}
ll qpow(ll n,ll k){
    ll res = 1;
    while(k){
        if(k&1) res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}
ll fac[N],inv[N];
ll push(int x,int y){
    return fac[x+y] * inv[x] % mod;
}
int a[N],n;
ll f[N][M];
ll calc(int i,int j){
    if(j<a[n]){
//        cout<<i<<' '<<j<<' '<<fac[n-i]*j<<endl;
        return fac[n-i] * j % mod;
    }
    ll &ans = f[i][j];
    if(ans!=-1) return f[i][j];
    ans = 0;
    int x = 0, y = 0;
    for(int k=i+1;k<=n;k++){
        if(a[k]<=j){
//            cout<<i<<','<<j<<','<<k<<','<<calc(k,j%a[k])*push(n-k,y)%mod*push(n-i-x,x)%mod<<endl;
            add(ans,calc(k,j%a[k])*push(n-k,y)%mod*push(n-i-x,x)%mod);
        }
        if(a[k]<=j) y++;
        else x++;
    }
//    cout<<i<<' '<<j<<' '<<ans<<endl;
    return ans;
}
int main(){
    fac[0] = 1; for(int i=1;i<N;i++) fac[i] = fac[i-1] * i % mod;
    inv[N-1] = qpow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1] * (i + 1) % mod;
    ios::sync_with_stdio(0);
    int x; cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    memset(f,-1,sizeof(f));
    cout<<calc(0,x)<<endl;
}

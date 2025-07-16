#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//使う前にCOMinit
//最大に注意！！！！！！！！！！！！！！！

int main() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans1=0;
    rep(i,n){
        ll num1=n-i;
        ans1+=num1*i*m*m;
        ans1%=MOD;
    }
    rep(i,m){
        ll num2=m-i;
        ans1+=num2*i*n*n;
        ans1%=MOD;
    }
    COMinit();
    if(n*m==2)cout<<ans1<<endl;
    else{
        ll ans=ans1*COM(n*m-2,k-2);
        ans%=MOD;
        cout<<ans<<endl;
    }

    

    return 0;
}
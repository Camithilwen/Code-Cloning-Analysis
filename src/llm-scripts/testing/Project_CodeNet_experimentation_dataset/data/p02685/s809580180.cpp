#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl
#define isort(a) sort(a.begin(),a.end())
#define ll long long

using namespace std;


#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

const ll inf =998244353;
typedef pair<ll,ll> Pair;


typedef vector<ll> vl;

const ll MAX = 510000;
const ll MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

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
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//繰り返し２乗
ll cal(ll x,ll n) {  // (K/x)^N　　
    int p = n;
    x %= inf;
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = (x * res) % inf; //pが奇数ならresはx倍される
        x = x * x % inf; //ここはxを二乗している
        p >>= 1; //pを二で割って、あまり切り捨てか。
    }
    return res;
}



void solve(){
    ll n,m,k;
    cin >> n >>m >>k;
    COMinit();
    ll ans=0;
    rep(j,k+1){
        ll score=m;
        score*=COM(n-1,j);
        score%=MOD;
        score*=cal(m-1,n-1-j);
        score%=MOD;
        ans+=score;
        ans%=MOD;
    }
    kaku(ans);
}

int main(){
    solve();
}
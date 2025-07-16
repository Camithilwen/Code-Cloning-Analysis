#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;
struct edge{int to, cost;};

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}

template <typename T>
vector<pair<T, T>> prime_factor(T n){
    vector<pair<T, T>> ret;
    for(T i=2; i*i<=n; i++){
        T tmp=0;
        while(n%i == 0){
            tmp++;
            n/=i;
        }
        if(tmp > 0) ret.push_back({i, tmp});
    }
    if(n != 1) ret.push_back({n, 1});
    return ret;
}

const int MAX=1001001;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD; //i!の計算
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD; //iの逆元の計算
        finv[i] = finv[i - 1] * inv[i] % MOD; //i!の逆元の計算
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll N, M; cin >> N >> M;
    
    vector<pii> p=prime_factor((int)M);
    COMinit();
    ll ans=1;
    for(int i=0; i<(int)p.size(); i++){
        ans=(ans*COM(p[i].second+N-1, N-1))%MOD;
    }
    cout << ans << endl;
    return 0;
}
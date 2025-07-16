#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

const int MAX = 1000000;
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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main()
{
    cout << fixed << setprecision(15);
    ll N, M, K;
    cin >> N >> M >> K;

    ll A = 1;
    A = (A*N)%MOD;
    A = (A*N)%MOD;
    A = (A*(M-1))%MOD;
    A = (A*M)%MOD;
    A = (A*(M+1))%MOD;

    ll B = 1;
    B = (B*M)%MOD;
    B = (B*M)%MOD;
    B = (B*(N-1))%MOD;
    B = (B*N)%MOD;
    B = (B*(N+1))%MOD;

    // 前処理
    COMinit();

    ll C = COM(N*M-2, K-2) % MOD;

    cout << ((((A+B)%MOD)* modinv(6, MOD) % MOD) * C) % MOD << endl;
    return 0;
}
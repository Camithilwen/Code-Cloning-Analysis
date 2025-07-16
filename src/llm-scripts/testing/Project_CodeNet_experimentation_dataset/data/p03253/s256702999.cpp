#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする　大きい値にする
template<class T> bool chmin(T &a, T b){ if(a>b) a = b; }
template<class T> void chmax(T &a, T b){ if(a<b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

// 最大公約数を求める GCD
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

/*
 * 素因数分解っぽいテーマの問題。こういうのは「まずは素数べきで考える」というのが 1 つの定石ではある。p を素数として

    a1×a2×...×aN=pk
    を満たす (a1,a2,...,aN) が何通りあるかを考える。これは実は、p の指数に着目して ai=pxi として、

    x1+x2+...+xN=k
    を満たす 0 以上の整数 (x1,x2,…,xN) が何通りあるかを数え上げる問題と考えることができる。

    これは重複組合せ！！！！！
    重複組合せは、「仕切りを使って考える」というのが 1 つの見方ではある。（●と｜を並べて考えるというものである）
    【N 個の玉と、k−1 個の仕切りの並び替え方を数える問題】
    nHk = c+k-1Ck で求められる

    M が素数べきについての考察を終えたので、一般の合成数について考えることになるのだが、実は各素因子についてまったく独立に考えることができる。
    つまり、上記のことを各素因子ごとに独立に行って、得られた結果を掛け算していけば OK。

 *
 * */


// 素因数分解 pair
vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

const int MAX = 210000;
const int MOD = 1000000007;

//  二項係数の計算nCk セット
//  https://drken1215.hatenablog.com/entry/2018/06/08/210000
//  使い方としては、最初に一度前処理として COMinit() をしておけば、あとは COM(n, k) 関数を呼べばよい
//  前処理 COMinit(): O(n)
//　クエリ処理 COM(n, k): O(1)
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
/**
 * // 前処理
    COMinit();

    // 計算
    cout << COM(100000, 50000) << endl;
    のようにつかう
 */
int main() {

    int N, M;
    COMinit();
    cin >> N >> M;
    auto vec = prime_factorize(M);
    long long res = 1;
    for (auto pa : vec) {
        int num = pa.second;
        long long tmp = COM(num+N-1, N-1);
        res = (res * tmp) % MOD;
    }
    cout << res << endl;
}
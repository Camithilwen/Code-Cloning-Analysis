#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

void _cin(){} template <class Head, class... Tail> void _cin(Head&& head, Tail&&... tail){ cin >> head; _cin(forward<Tail>(tail)...); }
void _cout(){ cout << "\n"; } template <class Head, class... Tail> void _cout(Head&& head, Tail&&... tail){ cout << head; _cout(forward<Tail>(tail)...); }
template<typename S, typename T> ostream& operator<<(ostream &os, const pair<S, T> &p){ cout << "[" << p.first << ", " << p.second << "]"; return os; }

#define Sq(x) (x)*(x)
#define For(i, n) for(int i = 0; i < (n); i ++)
#define Rep(n) For(_, n)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.rbegin(), c.rend()
#define Contains(c, x) (find(Range(c), x) != c.end())
#define Search(rb, re, x) distance(rb, find(rb, re, x))
#define Sort(a) sort(Range(a))
#define DeSort(a) sort(RevRange(a))
#define Reverse(c) reverse(Range(c))
#define Unique(a) a.erase(unique(Range(a)), a.end())
#define Cusum(T, xs, sxs) vector<T> sxs(xs.size()+1); For(i, (int)xs.size()) sxs[i+1] = sxs[i] + xs[i]
#define Cin(T, ...) T __VA_ARGS__; _cin(__VA_ARGS__)
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i]
#define Cins2(T, n, xs, ys) vector<T> xs(n), ys(n); For(i, n) cin >> xs[i] >> ys[i]
#define Cins3(T, n, xs, ys, zs) vector<T> xs(n), ys(n), zs(n); For(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cinm(T, n, map) unordered_map<T, int> map; Rep(n){ Cin(T, x); map[x] ++; }
#define Cout(...) _cout(__VA_ARGS__)
#define Couts(xs) { for(const auto &e : xs) cout << e << " "; cout << "\n"; }
#define Coutyn(cond) Cout((cond) ? "yes" : "no")
#define CoutYn(cond) Cout((cond) ? "Yes" : "No")
#define CoutYN(cond) Cout((cond) ? "YES" : "NO")
#define Return(expr) { Cout(expr); return 0; }
#define vc vector
#define Mini(a, x) a = min(a, x)
#define Maxi(a, x) a = max(a, x)

constexpr int MOD = 998244353;

ll modpow(ll n, ll p){
    if(p == 0) return 1;
    if(p % 2 == 1) return n * modpow(n, p-1) % MOD;
    ll t = modpow(n, p/2);
    return t*t % MOD;
}

constexpr int COMB_MAX = 210000;
ll fac[COMB_MAX], finv[COMB_MAX], inv[COMB_MAX];

void initComb(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COMB_MAX; i ++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void){
    Cin(int, n, m, k);
    initComb();
    
    ll ans = 0;
    For(i, k+1){
        ll tmp = m * modpow(m-1, n-i-1) % MOD * comb(n-i-1 + i, i) % MOD;
        // Cout(tmp);
        ans = (ans + tmp) % MOD;
    }
    Cout(ans);
}


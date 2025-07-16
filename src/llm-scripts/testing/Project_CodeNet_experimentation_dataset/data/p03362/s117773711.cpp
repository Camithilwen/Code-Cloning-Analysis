#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

struct Sieve {
    ll n;
    vi f;
    vi primes;
    // constructor
    Sieve(ll n=1) : n(n), f(n+1,0) {
        f.at(0) = -1;
        f.at(1) = -1;
        for(ll i = 2; i <= n; ++i){
            if (f.at(i)!=0) continue;
            primes.push_back(i);
            f.at(i) = i;
            for (ll j = i*i; j <= n; j += i) {
                if(f.at(j)==0) f.at(j) = i;
            }
        }
    }
    // xが素数かを判定
    bool isPrime(ll x) {
        return f.at(x) == x;
    }
    // xを素因数分解する関数(分解後の値を昇順の配列にして返す)
    // (100) => ([2,1,5,5]);
    vi primeFactorizedList(ll x) {
        vi res;
        while (x != 1) {
            res.push_back(f.at(x));
            x /= f.at(x);
        }
        return res;
    }
    // 素因数分解したときの各因数の個数をsecondに持つpairにする
    vector<P> primeFactorizedPair(ll x) {
        vi fl = primeFactorizedList(x);
        if (fl.size() == 0) return {};
        vector<P> res(1, P(fl.at(0), 0));
        for (ll p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            } else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    Sieve s = Sieve(55556);
    vi cand;
    for(ll p:s.primes){
        string str = to_string(p);
        if((str.at(str.size()-1)-'0')==1){
            cand.push_back(p);
        }
        if(cand.size()>55) break;
    }
    rep(i,n) cout << cand.at(i) << " ";
    cout << endl;
}
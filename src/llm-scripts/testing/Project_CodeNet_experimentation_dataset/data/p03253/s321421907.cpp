#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

template<class T>
vector<pair<T, T>> PrimeFactorization(T n) {
    vector<pair<T, T>> f;
    for (T i = 2; i * i <= n; i++) {
        T cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) f.push_back(make_pair(i, cnt));
    }
    if (n != 1) f.push_back(make_pair(n, 1));
    return f;
}

class Combination {
   public:
    Combination(int n) {
        fac = new ll[n];
        inv = new ll[n];
        finv = new ll[n];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        REP(i, 2, n) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    ll cnr(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }

   private:
    ll *fac, *inv, *finv;
};

int main() {
    int N, M; cin >> N >> M;
    auto factors = PrimeFactorization(M);
    int maximum = 0;
    for (auto f : factors) maximum = max(maximum, f.second);
    Combination comb(maximum + N);

    ll ans = 1;
    for (auto f : factors) {
        if (f.second == 0) continue;
        ans = ans * comb.cnr(f.second + N - 1, N - 1) % MOD;
    }
    cout << ans << endl;

    return 0;
}
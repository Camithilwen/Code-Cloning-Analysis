#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> Pli;

ll N, M;
const int MAX = 5.0e5 + 100;
const int MOD = 1.0e9 + 7;
ll fac[MAX], finv[MAX], inv[MAX];

vector<ll> primeFactorization(ll n) {
    vector<ll> ret;
    ll a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            ret.push_back(a);
            n /= a;
        } 
        else a++;
    }
    ret.push_back(n);
    return ret;
}

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

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    COMinit();

    cin >> N >> M;

    if (M == 1) {
        cout << 1 << endl;
    }
    else {
        vector<ll> pf = primeFactorization(M);
        map<ll, ll> mp;
        for (int i = 0; i < pf.size(); i++) {
            mp[pf[i]]++;
        }

        ll ans = 1;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            ll val = itr->second;
            ans = (ans * COM(N+val-1, val)) % MOD;
        }

        cout << ans << endl;
    }
    
    return 0;
}
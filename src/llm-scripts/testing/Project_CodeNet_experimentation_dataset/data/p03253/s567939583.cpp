#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<pair<int, int>, int> p;

#define MOD 1000000007

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    ll N, M;
    cin >> N >> M;

    map<ll, ll> a;

    for(ll i = 2LL; i * i <= M; i++) {
        while(M % i == 0) {
            a[i]++;
            M /= i;
        }
    }

    if(M != 1) a[M]++;

    ll ans = 1LL;

    for(auto i = begin(a); i != a.end(); i++) {
        ll c = 1LL;
        for(ll j = 0LL; j < i -> second; j++) {
            c *= (N + j) % mod;
            c %= mod;
            c *= modpow(j + 1LL, mod - 2LL, mod) % mod;
            c %= mod;
        }
        ans *= c;
        ans %= mod;
    }

    cout << ans % mod << endl;
}
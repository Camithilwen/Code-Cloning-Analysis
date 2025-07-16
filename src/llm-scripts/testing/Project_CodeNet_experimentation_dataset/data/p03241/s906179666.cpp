#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n, long long modvalue) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2, modvalue);
        return t * t % modvalue;
    } else {
        return modpow(m, n - 1, modvalue) * m % modvalue;
    }
}

long long moddiv(long long a, long long b, ll modvalue) { return (a * modpow(b, mod - 2, modvalue)) % modvalue; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k, ll modvalue) {
    ll numera = 1;
    for (int i = n; i > n - k; i--) {
        numera *= i;
        numera %= modvalue;
    }
    ll denomi = 1;
    REP(i, k) {
        denomi *= (i + 1);
        denomi %= modvalue;
    }
    return moddiv(numera, denomi, modvalue);
}

map<ll, ll> cnt;
void primeFactors(long long n) {
    while (n % 2 == 0) {
        cnt[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cnt[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        cnt[n]++;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    ll now = 0;
    for (int i = 1; i * i <= m; i++) {
        if (m % i == 0 && m / i >= n) {
            now = max(now, (ll)i);
        }
        if (m % i == 0 && m / (m / i) >= n) {
            now = max(now, (ll)m / i);
        }
    }
    cout << now << endl;
}
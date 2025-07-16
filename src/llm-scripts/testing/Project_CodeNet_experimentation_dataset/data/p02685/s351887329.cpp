#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

const ll MODULO = 998244353L;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

ll mod_pow(ll x, ll n, ll modval) {
    if (n == 0) {
        return 1;
    }
    ll res = mod_pow(x * x % modval, n / 2, modval);
    if (n & 1) {
        res = res * x % modval;
    }
    return res;
}
ll pow(ll x, ll n) {
    return mod_pow(x, n, MODULO);
}
ll mod(ll n) {
    return n % MODULO;
}

const ll COMBMAX = 200000;
ll factorial[COMBMAX+1], invfactor[COMBMAX+1];
void combination_init() {
    factorial[0] = 1;
    factorial[1] = 1;
    invfactor[0] = 1;
    invfactor[1] = 1;
    for (ll i = 2; i <= 1 + COMBMAX; i++) {
      factorial[i] = (i * factorial[i-1]) % MODULO;
      invfactor[i] = pow(factorial[i], MODULO-2);
    }
}
ll combination(ll n, ll k) {
    return mod(mod(factorial[n]*invfactor[k])*invfactor[n-k]);
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    combination_init();
    ll result = 0;
    for (ll j = 0; j <= K; j++) {
        result = mod(result + mod(combination(N - 1, j) * mod(M * pow(M - 1, N - j - 1))));
    }
    print(result);
}

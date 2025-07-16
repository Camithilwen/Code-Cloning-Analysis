/*
[jsc2019-qual] C - Cell Inversion
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N;
string S;
int cnt[2 * MAX_N];

ll solve() {
    if (S[0] == 'W' || S[2 * N - 1] == 'W') {
        return 0;
    }

    cnt[0] = 1;
    for (int i = 1; i < 2 * N; i++) {
        cnt[i] = (S[i - 1] == S[i]) ? (1 - cnt[i - 1]) : cnt[i - 1];
    }
    for (int i = 1; i < 2 * N; i++) {
        cnt[i] += cnt[i - 1];
    }
    if (cnt[2 * N - 1] != N) {
        return 0;
    }

    gf ans = 1;
    for (int i = 1; i < 2 * N; i++) {
        if (cnt[i - 1] == cnt[i]) {
            // R
            int p = 2 * cnt[i - 1] - i;
            if (p <= 0) {
                return 0;
            }
            ans *= p;
        }
    }
    for (int i = 1; i <= N; i++) {
        ans *= i;
    }

    return ans.n;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}

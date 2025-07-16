#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


const int MOD = 1e9 + 7;
int H, W, K;
vector<int> fib;
ll ans;


void input() {
    cin >> H >> W >> K;
}


int solve(int n) {
    if (n < 0) return 1;
    return fib[n];
}


int main() {
    input();
    fib = vector<int>(W);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < W; i++) fib[i] = fib[i-1] + fib[i-2];
    vector<ll> w1, w2;
    w1 = vector<ll>(W, 0);
    w1[0] = 1;
    rep(i, H) {
        w2 = vector<ll>(W, 0);
        for (int j = 0; j < W; j++) {
            if (j > 0) w2[j-1] = (w2[j-1] + w1[j] * solve(j-2) * solve(W-j-2)) % MOD;
            w2[j] = (w2[j] + w1[j] * solve(j-1) * solve(W-j-2)) % MOD;
            if (j < W - 1) w2[j+1] = (w2[j+1] + w1[j] * solve(j-1) * solve(W-j-3)) % MOD;
        }
        w1 = w2;
    }
    cout << w1[K-1] << endl;
}

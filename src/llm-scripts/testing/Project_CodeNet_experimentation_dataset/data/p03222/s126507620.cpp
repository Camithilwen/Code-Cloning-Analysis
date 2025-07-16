#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

ll MOD = 1E+9 + 7;

int main() {
    ll H, W, K;
    cin >> H >> W >> K;

    ll A[H+1][W+1] = {};
    A[0][1] = 1;
    ll c[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    for (ll h=0; h<H; h++) {
        for (ll w=1; w<=W; w++) {
            if (w>=2) A[h+1][w-1] = (A[h+1][w-1] + A[h][w] * c[w-2] * c[W-w]) % MOD;
            A[h+1][w] = (A[h+1][w] + A[h][w] * c[w-1] * c[W-w]) % MOD;
            if (w<W) A[h+1][w+1] = (A[h+1][w+1] + A[h][w] * c[w-1] * c[W-(w+1)]) % MOD;
        }
    }

    cout << A[H][K] << endl;

    return 0;
}

 
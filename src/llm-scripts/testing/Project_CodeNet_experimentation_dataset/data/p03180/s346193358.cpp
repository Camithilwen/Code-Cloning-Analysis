#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

const int N = 16;

int a[N + 1][N + 1];
ll value[1 << N];
ll f[1 << N];

int main() {
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i < (1 << n); ++i) {
        vector<int> vec;
        for(int j = 0; j < n; ++j) {
            if((i >> j)&1) vec.pb(j);
        }

        value[i] = 0;
        for(int x : vec) {
            for(int y : vec) {
                value[i] += a[x][y];
            }
        }
        value[i] /= 2;
    }

    for(int i = 0; i < (1 << n); ++i) {
        f[i] = 0;
        for(int j = i; j > 0; j = (j - 1)&i) {
            f[i] = max(f[i], value[j] + f[i^j]);
        }
    }

    cout << f[(1 << n) - 1] << endl;
}
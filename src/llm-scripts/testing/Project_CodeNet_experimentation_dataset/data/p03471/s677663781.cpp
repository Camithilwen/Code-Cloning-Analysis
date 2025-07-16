#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, y;
    cin >> n >> y;
    int a = -1, b = -1, c = -1;
    for (int i=0; i<=n; i++) {
        for (int j=0; i+j<=n; j++) {
            int k = n - i - j;
            if (10000 * i + 5000 * j + 1000 * k == y) {
                a = i; b = j; c = k;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
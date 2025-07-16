#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    int N, K, ans = 1;
    cin >> N >> K;
    rep(i, N) {
        if (ans < K) ans += ans;
        else ans += K;
    }
    cout << ans << "\n";
}
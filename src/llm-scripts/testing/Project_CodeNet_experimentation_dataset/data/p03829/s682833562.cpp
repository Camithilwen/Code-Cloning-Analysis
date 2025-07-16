#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll A, B;
    cin >> N >> A >> B;
    ll X[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    ll e[N- 1];
    for (int i = 0; i < N - 1; i++) {
        e[i] = X[i + 1] - X[i];
    }
    ll ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if (e[i] * A < B) ans += e[i] * A;
        else ans += B;
    }
    cout << ans << "\n";
    return 0;
}
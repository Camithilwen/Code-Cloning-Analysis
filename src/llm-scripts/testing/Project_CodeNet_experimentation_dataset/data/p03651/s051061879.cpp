#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);

    rep(i, N) {
        cin >> A[i];
        if (A[i] == K) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    ll m = *max_element(all(A));
    ll gcd = A[0];
    rep(i, N) { gcd = GCD(gcd, A[i]); }

    if (m < K) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if (gcd == 1) {
        cout << "POSSIBLE" << endl;
        return 0;
    }
    if (K % gcd == 0) {
        cout << "POSSIBLE" << endl;
        return 0;
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
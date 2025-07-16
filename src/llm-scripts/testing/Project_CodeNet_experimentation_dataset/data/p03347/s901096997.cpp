#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll sum = 0;
    vector<bool> B(N, false);
    if (A[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, N - 1) {
        if (A[i + 1] > A[i] + 1) {
            cout << -1 << endl;
            return 0;
        }
        if (A[i + 1] - A[i] == 1)
            B[i + 1] = true, sum++;
    }

    rep(i, N) {
        if (!B[i])
            sum += A[i];
    }

    cout << sum << endl;
}
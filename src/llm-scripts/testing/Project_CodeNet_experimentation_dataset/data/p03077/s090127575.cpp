// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    // ll N, A, B, C, D, E;
    // cin >> N >> A >> B >> C >> D >> E;
    ll N, A[5];
    cin >> N;
    rep(i, 5) cin >> A[i];
    sort(A, A + 5);

    ll mn = A[0];

    cout << (N + mn - 1) / mn + 4 << endl;


}
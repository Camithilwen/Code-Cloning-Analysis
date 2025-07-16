#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;cin >> n;
    vector<ll> A(n), abs_A(n);
    ll min_abs_A = 1e10;
    int minus_cnt = 0;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        abs_A[i] = abs(A[i]);
        min_abs_A = min(min_abs_A, abs_A[i]);
        if (A[i] < 0) minus_cnt++;
    }
    ll ans = accumulate(abs_A.begin(), abs_A.end(), 0LL);
    if (minus_cnt % 2) {
        ans -= min_abs_A * 2;
    }
    cout << ans << endl;
    return 0;
}
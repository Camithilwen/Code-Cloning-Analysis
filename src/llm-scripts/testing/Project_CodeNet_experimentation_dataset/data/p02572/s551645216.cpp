#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0, mul = a[0];
    for (int i = 1; i < n; i++){
        ans += (mul * a[i]) % MOD;
        ans %= MOD;
        mul += a[i];
        mul %= MOD;
    }

    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 1e5 + 5, MOD = 998244353;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i == 0 && x != 0) {
            cout << "0\n";
            return 0;
        }
        
        a[x]++;
        mx = max(mx, x);
    }

    if (a[0] != 1) {
        cout << "0\n";
        return 0;
    }

    ll ans = 1;

    for (int i = 1; i <= mx; i++) {
        for (int j = 0; j < a[i]; j++)
            ans = ans * a[i - 1] % MOD;
    }

    cout << ans << "\n";

    return 0;
}
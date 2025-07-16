#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define ZERO_IQ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x, y) cerr<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) << endl
#define debug2(x, y, z) cerr<<(#x)<<" " <<(#y)<<" " <<(#z)<<" is " << (x) <<" "<< (y) <<" "<<(z) << endl
#define watch(x) cerr<<(#x)<<" is " << (x) << endl

const int N = 2e5 + 10;
typedef long long ll;

ll dp[N];

int main() {
    ll n;
    cin >> n;
    vector<ll> v;
    vector<ll> summ(n + 1);
    for (int i = 1; i <= n; i++) {
        ll q;
        cin >> q;
        v.push_back(q);
        if (i % 2 == 1) {
            if (i == 1)summ[i] = q;
            else
                summ[i] = summ[i - 2] + q;
        }
    }
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 1) {
            dp[i] = max(dp[i - 2] + v[i - 1], dp[i - 1]);
        } else
            dp[i] = max(dp[i - 2] + v[i - 1], summ[i-1]);
    }
    cout << dp[n];
    return 0;
}
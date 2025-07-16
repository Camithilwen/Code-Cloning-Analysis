#include <bits/stdc++.h>

using ll = long long;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;

const ll INF = (ll)1e11;
const ll MOD = 998244353;

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A;
    ll S = 0;
    for (int i = 0, a; i < N; ++i) {
        cin >> a;
        A.push_back(a);
        S += a;
    }

    ll cnt = 1;
    for (int i = 0; i < N; ++i) {
        cnt *= 3;   // all ways to paint stones
        cnt %= MOD;
    }

    // subtract the numbers of ways to paint such that R,G,B cannot construct a triangle from all.

    {   // reduce the number of ways to paint such that R >= G + B, G >= B + R, B >= R + G
        vector<ll> dp(S + 10, 0);
        dp[0] = 1;  // assume that R = max(R,G,B) here
        for (auto a : A) {
            for (ll s = S; s > a - 1; --s) {
                dp[s] += 2 * dp[s-a];   // select a_i in G or B
                dp[s] %= MOD;
            }
        }
        
        for (ll s = 0; s < S / 2 + 1; ++s) {
            cerr << "----" << endl;
            cnt -= 3 * dp[s];   // subtract sum of R, G, B = max(R,G,B)
            while (cnt < 0) cnt += 3 * MOD;
            cnt %= MOD;
            
            cerr << cnt << endl;
        }
    }

    cerr << cnt << endl;

    if (S % 2 == 0) {   // add the number of ways to paint such that R == G && B == 0, G == B && R == 0, B == R && G == 0
        vector<ll> dp(S + 10, 0);
        dp[0] = 1;  // assume that R == G && B == 0 here
        for (auto&& a : A) {
            for (ll s = S; s > a - 1; --s) {
                dp[s] = (dp[s] + dp[s-a]) % MOD;   // select a_i in R (G)
                dp[s] %= MOD;
            }
        }

        cnt += 3ll * dp[S/2];   // add sum of R,G,B == 0
        cnt %= MOD;
    }

    cout << cnt << endl;

    return 0;
}

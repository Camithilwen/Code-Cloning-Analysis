#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    auto comp = [&](pair<ll, ll>& a, pair<ll, ll>& b) {
        return a.first + a.second < b.first + b.second;
    };

    sort(A.begin(), A.end(), comp);

    vector<vector<ll>> dp(2, vector<ll>(n + 1, 1e14));

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            dp[i%2][j] = dp[(i - 1)%2][j];


            if (A[i - 1].first >= dp[(i - 1)%2][j - 1]) {
                dp[i%2][j] = min(dp[i%2][j], A[i - 1].second + dp[(i - 1)%2][j - 1]);
            }
        }
    }

    // cout <<"dp array :: "<< "\n";

    // for(int i = 1 ; i <= n ;++i){
    //     for(int j = 1 ; j <= n ;++j){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int j = n; j >= 0; --j) {
        if (dp[n%2][j] != 1e14) {
            cout << j << "\n";
            break;
        }
    }

    return 0;
}

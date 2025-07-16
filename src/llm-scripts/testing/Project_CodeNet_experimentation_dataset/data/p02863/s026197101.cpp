#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, T;
    cin >> N >> T;
    vector<iint> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(ALL(A));

    vector<vector<int>> dp(N+1, vector<int>(T));
    int ans = 0;
    for (int i = 0; i < N+1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < T; i++) {
        dp[0][i] = 0;
    }
    for (int n = 1; n < N+1; n++) {
        for (int t = 1; t < T; t++) {
            if(t - A[n-1].first >= 0){
                dp[n][t] = max(dp[n-1][t], dp[n-1][t-A[n-1].first] + A[n-1].second);
            }
            else{
                dp[n][t] = dp[n-1][t];
            }
        }
        for (int t = T; t < T+A[n-1].first; t++) {
            if(t - A[n-1].first >= 0){
                ans = max(ans, dp[n-1][t-A[n-1].first] + A[n-1].second);
            }
        }
    }

    printf("%d\n", ans);

}
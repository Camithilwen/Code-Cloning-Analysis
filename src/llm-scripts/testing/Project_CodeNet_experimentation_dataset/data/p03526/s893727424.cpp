#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N;
vector<pii> P;

bool cmp(pii a, pii b) {
    return a.first + a.second < b.first + b.second;
}

ll dp[2][5002];

int main() {
    scanf("%d", &N);

    P.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &P[i].first, &P[i].second);
    }

    sort(P.begin(), P.end(), cmp);

    for(int i = 0; i < 5002; i++) dp[1][i] = 1e18;
    dp[1][0] = 0;
    for(int i = 0; i < N; i++) {
        dp[i&1][0] = 0;
        for(int j = 1; j <= N; j++) {
            dp[i&1][j] = 1e18;
            dp[i&1][j] = min(dp[i&1][j], dp[(i&1) ^ 1][j]);
            dp[i&1][j] = min(dp[i&1][j], dp[(i&1) ^ 1][j - 1] <= P[i].first? dp[(i&1) ^ 1][j - 1] + P[i].second : (ll)1e18);
        }
    }
    int ans = 0;
    for(int i = 0; i <= N; i++) if(dp[(N - 1) & 1][i] != 1e18) ans = i;
    printf("%d", ans);
}

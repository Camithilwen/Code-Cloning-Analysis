#include<bits/stdc++.h>
const int N = 5005;
const long long inf = 1e18;
using namespace std;

typedef pair <int, int> ii;
vector <ii> mv;

int n, ans;
long long dp[N][N], Min[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        x += y;
        mv.push_back(ii(x, y));
    }
    sort(mv.begin(), mv.end());
    for (int i = 0; i < N; i++) Min[i] = inf;
    Min[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--){
            if (mv[i-1].first - mv[i-1].second >= Min[j-1]) dp[i][j] = Min[j-1] + mv[i-1].second;
            else dp[i][j] = inf;
            Min[j] = min(Min[j], dp[i][j]);
            if (dp[i][j] != inf) ans = max(ans, j);
        }
    }
    cout << ans;
}

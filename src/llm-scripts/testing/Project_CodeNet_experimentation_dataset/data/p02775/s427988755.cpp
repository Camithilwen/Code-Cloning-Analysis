#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 5;
int dp[1000005][2];

int main(){
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    rep(i,n+1)rep(j,2) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n)rep(j,2){
        int x = s[i] - '0';
        x += j;
        if(x < 10) chmin(dp[i+1][0], dp[i][j] + x);
        if(x > 0) chmin(dp[i+1][1], dp[i][j] + (10 - x));
    }
    int ans = dp[n][0];
    cout << ans << endl;
}
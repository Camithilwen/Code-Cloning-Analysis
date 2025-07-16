#include <bits/stdc++.h>
using namespace std;

int cost[] = {0,2,5,5,4,5,6,3,7,6};
bool d[10] = {};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        d[a] = 1;
    }

    vector<string> dp(n+1, "");
    for (int j=0; j<=n; j++) {
        for (int i=1; i<10; i++) {
            if ( !d[i] ) continue;
            if ( j+cost[i]>n ) continue;
            if ( j && dp[j]=="" ) continue;
            string s=dp[j]+(char)(i+'0');
            if ( s.length()==dp[j+cost[i]].length() ) {
                dp[j+cost[i]]=max(s, dp[j+cost[i]]);
            } else if ( s.length()>dp[j+cost[i]].length() ) {
                dp[j+cost[i]]=s;
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
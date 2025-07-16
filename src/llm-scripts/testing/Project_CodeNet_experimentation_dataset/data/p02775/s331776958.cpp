#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,r) for (ll i = 0; i < (ll)(r); i++)

ll dp[1000010][2];

int main(){
    string s; cin >> s;
    s = '0' + s;
    int n = s.size();
    dp[0][1] = 1;
    for(int i=1;i<n;i++){
        int c = s[i]-'0';
        dp[i][0] = min(dp[i-1][0]+c, dp[i-1][1]+(10-c) );
        dp[i][1] = min(dp[i-1][0]+c+1, dp[i-1][1]+(10-c-1));
    }
    cout << dp[n-1][0] << endl;
}
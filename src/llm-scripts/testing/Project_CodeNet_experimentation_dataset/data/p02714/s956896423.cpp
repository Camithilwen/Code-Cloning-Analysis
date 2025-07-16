// ABC162-D RGB Triplets

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a, b, pos1, pos2;
    long long dp[3][4000] = {}, ans = 0;
    string s;

    cin >> n;
    cin >> s;

    ans = 0;
    for(int i=0 ;i<n ;i++ ) {
        if(s[i] == 'R') {
            dp[0][i] = 1;
        } 
        else if(s[i] == 'B') {
            dp[1][i] = 1;
        }
        else {
            dp[2][i] = 1;
        }

        if(i > 0) {
            for(int j=0 ;j<3 ;j++ ) {
                dp[j][i] += dp[j][i-1];
            }
        }
    }

    for(int i=1 ;i<n-1 ;i++ ) {  
        if(s[i] == 'R') {
            a = 1;
            b = 2;
        }
        else if(s[i] == 'B') {
            a = 0;
            b = 2;
        }
        else {
            a = 0;
            b = 1;
        }

        ans += dp[a][i-1] * (dp[b][n-1] - dp[b][i]) + dp[b][i-1] * (dp[a][n-1] - dp[a][i]);
        pos1 = i-1;
        pos2 = i+1;   

        while(pos1 >= 0 && pos2 <= n-1) {
            if(s[pos1] != s[i] && s[i] != s[pos2] && s[pos1] != s[pos2]) {
                ans --;
            }

            pos1 --;
            pos2 ++;
        }
    }

    cout << ans << endl;

    return (0);
}
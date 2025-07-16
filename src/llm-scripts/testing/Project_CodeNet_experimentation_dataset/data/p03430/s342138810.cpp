#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;
int dp[MAXN][MAXN][MAXN];

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int sz = 1; sz <= s.size(); sz++){
        for(int l = 0; l < s.size() - sz + 1; l++){
            int r = l + sz - 1;
            for(int j = 0; j <= k; j++){
                if(r == l){
                    dp[l][r][j] = 1;
                    continue;
                }
                if(r - l == 1){
                    if(j == 0){
                        if(s[l] == s[r]){
                            dp[l][r][j] = 2;
                        }
                        else{
                            dp[l][r][j] = 1;
                        }
                    }
                    else{
                        dp[l][r][j] = 2;
                    }
                    continue;
                }
                dp[l][r][j] = max(dp[l + 1][r][j], dp[l][r - 1][j]);
                if(s[l] == s[r]){
                    dp[l][r][j] = max(dp[l][r][j], dp[l + 1][r - 1][j] + 2);
                }
                else if(j != 0){
                    dp[l][r][j] = max(dp[l][r][j], dp[l + 1][r - 1][j - 1] + 2);
                }
            }
        }
    }
    cout << dp[0][s.size() - 1][k];
}

#include <bits/stdc++.h>
using namespace std;

string s;
int memo[310][310][310];

int dp(int l, int r, int k){
    if(l > r){
        return 0;
    }

    if(l == r){
        return 1;
    }

    if(memo[l][r][k] != -1) return memo[l][r][k];

    int ans = 0;
    ans = max(ans, dp(l+1, r, k));
    ans = max(ans, dp(l, r-1, k));

    if(s[l] == s[r]){
        ans = max(ans, dp(l+1, r-1, k)+2);
    }else if(k > 0){
        ans = max(ans, dp(l+1, r-1, k-1)+2);
    }

    return memo[l][r][k] = ans;
}

int main(){
    cin >> s;
    int k;
    cin >> k;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, s.size()-1, k) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MOD = 1e9+7;


string s; 
ll d, n;
ll dp[10005][101][2];  // k = 0, cannot cross limit, k = 1 can

ll solve(ll i, ll sum, ll k){
    if(i == n) return sum == 0;
    if(dp[i][sum][k] == -1) {
    ll dig = s[i] - '0';
    if(k) dig = 9;
    
ll res = 0;
    for(int j = 0; j <= dig; j++){
    res += solve(i+1, (sum + j)%d, (k == 1 ||  (k == 0 && j < dig ) ? 1 : 0)  );
    res %= MOD;
}
dp[i][sum][k] = res;
}
return dp[i][sum][k];
}
 
int main(){
    cin >> s >> d;
    n = s.size();
    
    memset(dp, -1, sizeof(dp));

    cout << (solve(0, 0, 0) - 1 + MOD)%MOD;
    
}



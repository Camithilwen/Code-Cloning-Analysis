#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 6010;
int MOD;

int dp[N][2*N];

int add(int a, int b){
    return (a + b) % MOD;
}
 
int mul(ll a, int b){
    return (a * b) % MOD;
}

void sadd(int &a, int b){
    a = add(a, b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;cin >> n >> MOD;
    n *= 3;
    dp[0][n] = 1;

    for(int i=1 ; i<=n ; i++)
        for(int j=0 ; j<=2*n ; j++){
            if(j)
                sadd(dp[i][j], dp[i-1][j-1]);
            if(i>1)
                sadd(dp[i][j], mul(i-1, dp[i-2][j+1]));
            if(i>2)
                sadd(dp[i][j], mul((i-1)*(i-2), dp[i-3][j]));
        }

    int ans=0;

    for(int i=n ; i<=2*n ; i++)
        sadd(ans, dp[n][i]);
    cout << ans << "\n";
}

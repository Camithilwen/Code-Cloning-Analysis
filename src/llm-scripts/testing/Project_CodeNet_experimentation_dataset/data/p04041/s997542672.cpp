#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;

#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define eb emplace_back
const int mod = 1e9+7;

int dp[45][1<<17];
int main(){
    int n, x, y, z;
    scanf("%d%d%d%d", &n, &x, &y, &z);
    int b = (1<<(x+y+z-1))|(1<<(y+z-1))|(1<<(z-1));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<17);j++){
            if(dp[i-1][j] == 0) continue;
            for(int k=1;k<=10;k++){
                int nt = (j<<k) + (1<<(k-1));
                nt &= (1<<17)-1;
                if((nt&b) == b) continue;
                dp[i][nt] = (dp[i][nt] + dp[i-1][j])%mod;
            }
        }
    }
    ll ans = 1;
    for(int i=1;i<=n;i++) ans = ans*10%mod;
    for(int j=0;j<(1<<17);j++) ans = (ans - dp[n][j] + mod)%mod;
    printf("%lld\n", ans);
}
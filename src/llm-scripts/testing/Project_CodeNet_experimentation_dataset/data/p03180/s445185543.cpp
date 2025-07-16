#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 998244353;
const ll INF = 1e18;
using namespace std;

ll dp[1 << 20], pre[1 << 20];

main(){    
    #ifdef XOX
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\Input.txt", "r", stdin);
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\OPT.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(!cin.tie(NULL));
    
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));

    ll tmp, mask;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tmp;
            mask = (1 << i)|(1 << j);
            dp[mask] += tmp;
        }
    }

    for(int i = 0; i < n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(mask&(1 << i))   dp[mask] += dp[mask^(1 << i)];
        }
    }

    for(int mask = 0; mask < (1 << n); mask++){
        pre[mask] = dp[mask];
        for(int sub = mask; sub; sub = (sub - 1)&mask){
            pre[mask] = max(pre[mask], pre[sub] + dp[mask^sub]);
        }
    }

    cout << pre[(1 << n) - 1] / 2;  

}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    vector<vector<int>> accum(1<<20);
    int now = 0;
    vector<ll> zero(N+1, 0);
    for (int i = 0; i < N; i++) {
        now ^= A[i];
        accum[now].push_back(i+1);
        if (now == 0) zero[i+1]++;
    }
    
    for (int i = 0; i < N; i++) {
        zero[i+1] += zero[i];
    }
    
    ll mod = 1e9+7;
    
    if (now > 0) {
        int K = accum[now].size(); 
        vector<ll> dp0(K+1, 0), dp1(K+1, 0);
        dp0[0] = 1;
        
        for (int i = 1; i <= K; i++) {
            if (i == 1) {
                dp0[i] = 1;
                dp1[i] = 1;
            }
            else {
                ll n = zero[accum[now][i-1]] - zero[accum[now][i-2]];
                dp0[i] = (dp0[i-1] + n * dp1[i-1]) % mod;
                dp1[i] = (dp0[i-1] + (n+1) * dp1[i-1]) % mod;
            }
        }
        cout << dp0[K]%mod << endl;
    }
    else {
        ll ans = 1;
        for (int i = 0; i < (int)accum[0].size()-1; i++) {
            ans = ans * 2 % mod;
        }
        
        for (int i = 1; i < (1<<20); i++) {
            if (accum[i].empty()) continue;
            int K = accum[i].size(); 
            vector<ll> dp0(K+1, 0), dp1(K+1, 0);
            dp0[0] = 1;
        
            for (int j = 1; j <= K; j++) {
                if (j == 1) {
                    dp0[j] = 1;
                    dp1[j] = 1;
                }
                else {
                    ll n = zero[accum[i][j-1]] - zero[accum[i][j-2]];
                    dp0[j] = (dp0[j-1] + n * dp1[j-1]) % mod;
                    dp1[j] = (dp0[j-1] + (n+1) * dp1[j-1]) % mod;
                }
            }
            ans += dp1[K];
        }
        cout << ans%mod << endl;
    }
    
    return 0;
}
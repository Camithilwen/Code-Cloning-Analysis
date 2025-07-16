#include <bits/stdc++.h>
using namespace std; 
const int maxn = 5000500;
const int mod = 1e9 + 7;
int a[maxn], pref[maxn], cntzer[maxn];
long long dp[maxn];
vector < int > v[maxn];
long long add(long long a, long long b){
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

long long mul(long long a, long long b){
    return (a * b) % mod;
}

long long solve_fixed(int n, int X){
    dp[pref[n - 1]] = 1;
    long long ans = (pref[n - 1] == X ? 1:0);
    for(int i = n - 2 ; i >= 0 ; --i){
        if(pref[i] == X) ans = add(ans, dp[0]);
        dp[pref[i]] = add(dp[pref[i]],dp[X ^ pref[i]]);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long xr = 0;
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i];
    pref[0] = a[0];
    cntzer[0] = (a[0] ? 0:1);
    v[a[0]].push_back(0);
    for(int i = 1 ; i < n ; ++i){
        pref[i] = a[i] ^ pref[i - 1];
        cntzer[i] = !pref[i] + cntzer[i - 1];
        v[pref[i]].push_back(i);
    }
    long long ans = solve_fixed(n, 0);
    for(int i = 1 ; i < maxn ; ++i){
        if((int)v[i].size() == 0 || (v[i][(int)v[i].size() - 1] != n - 1 && pref[n - 1])) continue;
        long long smx = 1, sm0 = !pref[n - 1];
        ans = add(ans, smx);
        for(int j = (int)v[i].size() - 2 ; j >= 0 ; --j){
            sm0 = add(sm0, mul(cntzer[v[i][j + 1]] - cntzer[v[i][j]], smx));
            ans = add(ans, sm0);
            smx = add(smx, sm0);
        }
    }
    cout << ans << '\n';
    return 0;

}
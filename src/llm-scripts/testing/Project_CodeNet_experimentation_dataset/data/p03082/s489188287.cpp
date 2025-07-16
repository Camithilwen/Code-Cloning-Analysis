#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 35000;
const int K = 19;
int mod =  1e9 + 7;
int n, dp[210][100200], a[N], f[N], invf[N];
int solve(int m, int x){
    if (m > n) return dp[m][x] = x;
    if (dp[m][x] != 0) return dp[m][x];
    int cnt = 0;
    int l = m;
    while (l <= n && a[l] > x){
        cnt++;
        l++;
    }
    if (cnt != 0) return dp[m][x] = f[n - m + 1] * invf[n - m - cnt + 1] % mod * solve(m + cnt, x) % mod;
    int res = 0;
    for (int i = m; i <= n; i++){
        res = (res + f[n - m] * invf[n - i] % mod * solve(i + 1, x % a[i])) % mod;
    }
    return dp[m][x] = res;
}
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int x;
    cin >> n >> x;
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invf[i] = binpow(f[i], mod - 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    cout << solve(1, x);
}

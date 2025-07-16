#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
//#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 3000000;
int mod = 1e9 + 7;
int s[N], dp[N][2], b[N];
map < int, int > m;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    s[0] = 0;
    set < int > t;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s[i] = (s[i - 1] ^ x);
        t.insert(s[i]);
    }
    t.insert(0);
    int cnt = 0;
    for (auto i: t){
        m[i] = cnt;
        cnt++;
    }
    for (int i = 1; i <= cnt; i++) dp[i][0] = 1;
    int g = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == 0){
            g++;
        } else{
            int p = m[s[i]];
            if (b[p] < g){
                dp[p][0] = (dp[p][0] + (g - b[p]) * dp[p][1]) % mod;
                b[p] = g;
            }
            dp[p][1] = (dp[p][1] + dp[p][0]) % mod;
        }
    }
    if (s[n] == 0){
        int c = 1;
        for (int i = 1; i < n; i++) if (s[i] == 0) c = (c + c) % mod;
        for (int i = 1; i <= cnt; i++){
            c = (c + dp[i][1]) % mod;
        }
        cout << c << endl;
    }
    else {
        int p = m[s[n]];
        if (b[p] < g)  dp[p][0] = (dp[p][0] + (g - b[p]) * dp[p][1]) % mod;
        cout << dp[p][0];

    };
}

#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int INF = -1e18;
const int N = 16;
ll cost[1<<N];
ll dp[1<<N];
int n;

ll f(int mask) {
    if (mask == 0) return 0;
    ll &r = dp[mask];
    if (r != -1) return r;
    
    r = -INF;
    for (int sub = mask; sub; sub = (sub-1)&mask) {
        int next = mask&~sub;
        r = max(r, f(next) + cost[sub]);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    int g[n][n];
    forn(i, 0, n) {
        forn(j, 0, n) {
            cin >> g[i][j];
        }
    }
    
    forn(mask, 1, 1<<n) {
        forn(i, 0, n) if ((mask>>i)&1) {
            forn(j, i, n) if ((mask>>j)&1) {
                cost[mask] += g[i][j];
            }
        }
    }
    
    int mask = (1<<n)-1;
    memset(dp, -1, sizeof dp);
    ll ans = f(mask);
    
    cout << ans << endl;
}

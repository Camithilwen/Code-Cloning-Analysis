#include<bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);
 
int N, M;
int adj[15][15], stor[1<<15][15], dp[1<<15][15];
vector<pii> nex[1<<15];
 
void gen(int i, int cur, int todo, int cost) {
    if (todo == N) {
        nex[i].pb({cur,cost});
        return;
    }    
    if ((i & (1<<todo)) == 0) gen(i,cur+(1<<todo),todo+1,cost+stor[i][todo]);
    gen(i,cur,todo+1,cost);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,M) {
        int a,b,c; cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = adj[b][a] = c;
    }
    
    F0R(i,1<<N) {
        F0R(j,N) {
            int tot = 0;
            F0R(k,N) if (i & (1<<k)) tot += adj[j][k];
            stor[i][j] = tot;
        }
        gen(i,0,0,0);
    }
    
    F0R(i,1<<N) F0R(j,N) dp[i][j] = MOD;
    dp[1][0] = 0;
    
    F0R(i,1<<N) if (i&1) F0R(j,N) if (i&(1<<j)) {
        F0R(k,N) if ((i&(1<<k)) == 0) if (adj[j][k]) dp[i^(1<<k)][k] = min(dp[i^(1<<k)][k],dp[i][j]+stor[i^(1<<j)][k]);
        for(pii a: nex[i]) dp[i^a.f][j] = min(dp[i^a.f][j],dp[i][j]+a.s-stor[a.f][j]);
    }
    
    cout << dp[(1<<N)-1][N-1];
}

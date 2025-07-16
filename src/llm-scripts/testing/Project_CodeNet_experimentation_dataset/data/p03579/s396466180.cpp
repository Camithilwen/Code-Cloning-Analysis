#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
vector<int> G[100010];

int color[100010];

// 頂点を1と-1で塗っていく
bool dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++) {
        // 隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c) return false;
        // 隣接している頂点がまだ塗られていないなら-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }

    // すべての頂点を塗れたらtrue
    return true;

}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    if(dfs(0, 1)) {
        int k1 = 0, k2 = 0;
        rep(i, 100010) {
            if (color[i] == 1) k1++;
            else if (color[i] == -1) k2++;
        }
        cout << k1 * k2 - M << endl;
    } else {
        cout << N * (N - 1) / 2 - M << endl;
    }



    return 0;
}

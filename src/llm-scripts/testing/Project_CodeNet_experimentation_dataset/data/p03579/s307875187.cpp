#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

vvi con(100050);
V(bool) visited(100050, false);
vi bw(100050, 0);
bool exr = false;

void dfs(int now, int cost, int past) {
    bw[now] = cost%2;
    rep(i, con[now].size()) {
        if(!visited[con[now][i]]) {
            visited[con[now][i]] = true;
            dfs(con[now][i], cost+1, now);
        } else if(con[now][i] != past) {
            if(bw[con[now][i]]==bw[now]) exr = true;
        }
    }
}

signed main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        con[a].pb(b);
        con[b].pb(a);
    }

    dfs(0, 0, -1);
    
    if(exr) cout << N*(N-1)/2 - M << endl;
    else {
        int b=0, w=0;
        rep(i, N) {
            if(bw[i]==0) b++;
            else w++;
        }
        cout << b*w-M << endl;
    }
        
    
    return 0;
}
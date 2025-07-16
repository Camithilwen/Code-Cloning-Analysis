#include <bits/stdc++.h>
#include <algorithm>
#include <time.h>
#define l(x) x<<1
#define r(x) ((x<<1) | 1)
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int inf = 2*(1e9) + 10;
const long long MOD =998244353;
const int NMAX = 1000005;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

vector<int> G[NMAX];
int viz[NMAX], color[NMAX];
bool bip;

int dfs(int v, int p){
    for(auto el: G[v]){
        if(el == p){
            continue;
        }
        if(viz[el]){
            if(color[el] != 1-color[v]){
                bip = 0;
            }
        } else {
            color[el] = 1 - color[v];
            viz[el] = 1;
            dfs(el, v);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 1; i<=m; ++i){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    LL ans = 0;
    LL sum = 0;
    LL ons = 0;
    LL bp = 0;
    LL bm = 0;
    for(int i=1; i<=n; ++i){

        if(G[i].size() == 0){
            ons++;
            continue;
        }
        if(viz[i]){ continue;}
        bip = 1;
        viz[i] = 1;
        dfs(i, 0);
        if(bip){
            bp++;
        } else bm++;
    }
    cout<<2*ons*n - ons*ons + bm*bm + 2*bm*bp + 2*bp*bp<<"\n";

    return 0;
}

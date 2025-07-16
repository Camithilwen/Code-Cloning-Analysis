#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll N, M, i, x, y, f, val[MN], c1, c2, ans, sz;
vector<ll> adj[MN];
void dfs(int n){
    for(auto v : adj[n]){
        if(val[v]==-1) val[v]=!val[n], dfs(v);
        else if(val[v]==val[n]) f=1;
    }
}
int main(){
    for(scanf("%lld%lld",&N,&M),i=1;i<=M;i++){
        scanf("%lld%lld",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(val,-1,sizeof(val));
    for(i=1;i<=N;i++){
        if(adj[i].size()) sz++;
        if(val[i]!=-1||adj[i].empty()) continue;
        f=0; val[i]=0; dfs(i);
        if(!f) ans+=2*(c1+2*c2)+2, c2++;
        else ans+=2*(c1+c2)+1, c1++;
    }
    ans += N*N-sz*sz;
    printf("%lld\n",ans);
    return 0;
}

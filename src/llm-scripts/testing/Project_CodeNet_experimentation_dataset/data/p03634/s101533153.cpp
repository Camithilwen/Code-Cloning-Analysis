#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};

vector<lint> G[200050]; // MAX_V,隣接リスト
lint root;

lint parent[20][200050]; // logMAX_V,MAX_V
lint depth[200050];

void LCAdfs(lint v,lint p,lint d){
    parent[0][v]=p;
    depth[v]=d;
    rep(i,G[v].size()) if(G[v][i]!=p) LCAdfs(G[v][i],v,d+1);
}

void LCAinit(lint V){
    LCAdfs(root,-1,0);
    for(int k=0;k+1<20;k++){
        for(int v=0;v<V;v++){
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}

lint LCA(lint u,lint v){
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<20;k++){
        if((depth[v]-depth[u])>>k&1) v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=20-1;k>=0;k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

vector<int> path(int s,int t){
    int lca=LCA(s,t);
    vector<int> ps,pt;
    int now=s;
    while(true){
        if(now==lca) break;
        ps.push_back(now);
        now=parent[0][now];
    }
    now=t;
    while(true){
        pt.push_back(now);
        if(now==lca) break;
        now=parent[0][now];
    }
    reverse(pt.begin(),pt.end());
    ps.insert(ps.end(),pt.begin(),pt.end());
    return ps;
}

vector<pint> edge[MAX_N];
bool reach[MAX_N];
lint dis[MAX_N];

void dfs(int now,lint sum){
    if(reach[now]) return;
    reach[now]=true;
    dis[now]=sum;
    rep(i,edge[now].size()){
        dfs(edge[now][i].fi,sum+edge[now][i].se);
    }
}


int main(void){
    int N;
    cin >> N;
    rep(i,N-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edge[u].push_back(pint(v,w));
        edge[v].push_back(pint(u,w));
    }
    LCAinit(N);
    dfs(0,0);
    int Q,K;
    cin >> Q >> K;
    K--;
    rep(i,Q){
        int x,y;
        cin >> x >> y;
        x--,y--;
        int lca=LCA(x,K);
        lint ans=dis[x]+dis[K]-2*dis[lca];
        lca=LCA(K,y);
        ans+=dis[K]+dis[y]-2*dis[lca];
        cout << ans << endl;
    }
}
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
// #define int ll
// #define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
 
const int N=1e5+5,OO=1e9;
vector<pii> gg[N];
vector<int> v[N];
vector<int> num[N];
int xx[N*4],zz[N*4],dist[N*4];
vector<vector<int>> g[N];
int u[N];
int q[N*8];
int32_t main(){
    int n,m;
    cin>>n>>m;
    forn(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        gg[x].pb(y,z);
        gg[y].pb(x,z);
        v[x].pb(z);
        v[y].pb(z);
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        sort(v[i].begin(), v[i].end());
        v[i].resize(unique(v[i].begin(), v[i].end())-v[i].begin());
        g[i].resize(sz(v[i]));
        num[i].resize(sz(v[i]));
        forn(j,sz(v[i])){
            xx[cnt]=i;zz[cnt]=j;
            dist[cnt]=OO;
            num[i][j]=cnt++;
        }
        for(pii p:gg[i]){
            int to=p.f,z=p.s;
            z=lower_bound(v[i].begin(), v[i].end(),z)-v[i].begin();
            g[i][z].pb(to);
        }
    }
    int l=N*3,r=N*3;
    forn(i,sz(v[1])){
        dist[num[1][i]]=1;
        q[r++]=num[1][i];
    }
    u[1]=1;
    while(l<r){
        int nu=q[l++];
        int x=xx[nu],pz=zz[nu];
        int z=v[x][pz];
        if(!u[x]){
            u[x]=1;
            forn(i,sz(v[x])){
                int nt=num[x][i];
                if(dist[nt]>dist[nu]+1){
                    dist[nt]=dist[nu]+1;
                    q[r++]=nt;
                }
            }
        }
        for(int to:g[x][pz]){
            int pzt=lower_bound(v[to].begin(), v[to].end(),z)-v[to].begin();
            int nt=num[to][pzt];
            if(dist[nt]>dist[nu]){
                dist[nt]=dist[nu];
                q[--l]=nt;
            }
        }
    }
    int ans=OO;
    forn(i,sz(v[n]))upn(ans,dist[num[n][i]]);
    if(ans==OO)ans=-1;
    cout<<ans<<'\n';
    return 0;
}
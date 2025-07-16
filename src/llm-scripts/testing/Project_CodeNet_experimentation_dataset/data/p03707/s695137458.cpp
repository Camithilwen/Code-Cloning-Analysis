#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
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
const int N=2020;
int a[N][N],el[N][N],eu[N][N],p[N][N];
int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i){
        string s;cin>>s;s="#"+s;
        for(int j=1;j<=m;++j){
            a[i][j]=s[j]-'0';
            int pl=a[i][j]&a[i][j-1];
            int pu=a[i][j]&a[i-1][j];
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
            el[i][j]=el[i-1][j]+el[i][j-1]-el[i-1][j-1]+pl;
            eu[i][j]=eu[i-1][j]+eu[i][j-1]-eu[i-1][j-1]+pu;
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int v=p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
        int e=el[x2][y2]-el[x2][y1]-el[x1-1][y2]+el[x1-1][y1]+
            eu[x2][y2]-eu[x2][y1-1]-eu[x1][y2]+eu[x1][y1-1];
        cout<<v-e<<'\n';
    }
    return 0;
}
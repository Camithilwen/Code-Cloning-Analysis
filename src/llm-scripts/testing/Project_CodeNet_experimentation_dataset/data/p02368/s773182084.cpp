#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
typedef long long int lli;
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vc vector<char>
#define vs vector<string>
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*-------CONSTANTS------- */
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
const int INF = 1000000000;
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
/*-----------------------------MATH STUFF----------------------------- */
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mulmod(int a, int b, int c){lli res=(lli)a*b;return(res>=c?res%c:res);}
template<typename T>T power_mod(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mulmod(x,p,m);p=mulmod(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
//Factorials upto 1e5%MOD,nCr%MOD,nPr%MOD
lli fact[100000+5],fact_modinv[100000+5];
void fact_init(){
    fact[0] = 1ll;
    fact_modinv[0] = mod_inverse(fact[0],1ll*MOD);
    for(int i = 1;i<=100000;i++){
        fact[i] = mulmod(fact[i-1],i,1ll*MOD);
        fact_modinv[i] = mod_inverse(fact[i],1ll*MOD);
    }
}
lli choose(int n,int r){
    return mulmod(fact_modinv[n-r],mulmod(fact[n],fact_modinv[r],MOD),MOD);
}
lli P(int n,int r){
    return mulmod(fact[n],fact_modinv[n-r],1ll*MOD);
}
/*-----------------------------START----------------------------- */


int n,m;
vector<int> g[10000+5],gr[10000+5];
vector<int> topo;
bool visited1[10000+5],visited2[10000+5];
vector<int> scc[10000+5];
int par[10000+5];
void dfs(int u){
    visited1[u] = true;
    for(auto x : g[u])
        if(!visited1[x])
            dfs(x);

    topo.push_back(u);
}

void dfs2(int u,int p){
    visited2[u] = true;
    par[u] = p;

    for(auto x : gr[u])
        if(!visited2[x])
            dfs2(x,p);
}
int main(){
    fastio;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        gr[v].pb(u);
    }
    for(int i = 0;i<n;i++)
        if(!visited1[i])
            dfs(i);

    reverse(topo.begin(),topo.end());
    
    for(auto x : topo)
        if(!visited2[x])
            dfs2(x,x);


    int q;cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<(par[u] == par[v])<<endl;
    }

    
    return 0;
}



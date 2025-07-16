#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n,m;
ll num[10]={2,5,5,4,5,6,3,7,6};
string dp[11000];
void chmax2(string &a,string b){
    if(a=="-") a=b;
    if(a.size()<b.size()) a=b;
    else if(a.size()==b.size()){
        if(a<b) a=b;
    }
}
int main(){
    cin>>n>>m;
    vl a(m);rep(i,m)cin>>a[i];
    rep(i,11000)dp[i]="-";
    dp[0]="";
    for(int i=0;i<=n;i++){
        if(dp[i]=="-") continue;
        for(auto aa:a){
            string b=dp[i]+(char)('0'+aa);
            chmax2(dp[i+num[aa-1]],b);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
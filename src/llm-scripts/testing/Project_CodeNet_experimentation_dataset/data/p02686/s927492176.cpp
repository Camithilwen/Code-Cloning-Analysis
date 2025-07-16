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
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
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
ll n;
bool ok(vector<l_l> ls){
    ll h=0;
    rep(i,sz(ls)){
        ll b=ls[i].fi;
        if(h+b<0)return false;
        h+=ls[i].se;
    }
    return true;
}
int main(){
    cin>>n;
    vector<l_l> ls,rs;
    ll tot=0;
    rep(i,n){
        string s;cin>>s;
        ll h=0,b=0;
        rep(j,sz(s)){
            if(s[j]=='(')h++;
            else h--;
            b=min(b,h);
        }
        tot+=h;
        if(h>=0)ls.pb({b,h});
        else rs.pb({b-h,-h});
    }
    sort(ls.rbegin(),ls.rend());
    sort(rs.rbegin(),rs.rend());
    if(ok(ls)&&ok(rs)&&tot==0){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}
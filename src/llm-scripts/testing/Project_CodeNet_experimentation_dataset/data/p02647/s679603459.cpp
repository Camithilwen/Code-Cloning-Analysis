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
int main(){
    ll n,k;cin>>n>>k;
    vl a(n);
    rep(i,n)cin>>a[i];
    rep(t,k){
        vl imos(n+1);
        rep(i,n){
            imos[max(i-a[i],0ll)]++;
            imos[min(i+a[i]+1,n)]--;
        }
        rep(i,n)imos[i+1]+=imos[i];
        imos.pop_back();
        if(imos==a)break;
        a=imos;
    }
    rep(i,n)cout<<a[i]<<" ";cout<<endl;
}
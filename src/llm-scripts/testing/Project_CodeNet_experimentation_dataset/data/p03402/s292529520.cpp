#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
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
    ll a,b;cin >> a >>b;
    cout << 100 <<" " <<100 <<endl;
    vector<vector<char>> g(100,vector<char>(100,'.'));
    rep(i,50){
        rep(j,100){
            g[i][j]='#';
        }
    }
    a--;b--;
    ll i=0,j=0;
    while(a!=0){
        if(j%2==0){g[i][j]='.';a--;}
        j++;if(j==100){j=0;i+=2;}
    }
    i=99;j=99;
    while(b!=0){
        if(j%2==0){g[i][j]='#';b--;}
        j--;if(j==-1){j=99;i-=2;}
    }
    rep(i,100){
        rep(j,100){
            cout << g[i][j];
        }
        cout <<endl;
    }
}
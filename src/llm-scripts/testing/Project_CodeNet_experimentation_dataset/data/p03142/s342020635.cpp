#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,m;cin>>n>>m;
    vector<ll>par(n+1);
    vector<ll>dim(n+1);
    vector<vector<ll> >G(n+1);
    rep(i,n+m-1){
        ll a,b;cin>>a>>b;
        dim[b]++;
        G[a].pb(b);
    }
    queue<ll>q;
    ll p;
    REP(i,1,n+1){
        if(dim[i]==0)p=i;
    }
    q.push(p);
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        for(auto e:G[now]){
            dim[e]--;
            if(dim[e]==0){
                par[e]=now;
                q.push(e);
            }
        }
    }
    REP(i,1,n+1){
        cout<<par[i]<<endl;
    }
}
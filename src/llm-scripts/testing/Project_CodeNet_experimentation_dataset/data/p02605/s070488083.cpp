#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e18
#define mod 1000000007

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  vector<ll> X(N),Y(N),K(N);
  rep(i,N){
    char c;
    cin>>X[i]>>Y[i]>>c;
    if(c=='R')K[i]=0;
    if(c=='U')K[i]=1;
    if(c=='L')K[i]=2;
    if(c=='D')K[i]=3;
  }

  ll res=INF;

  {
    vector<ll> keys;
    rep(i,N){
      keys.push_back(Y[i]-X[i]);
    }
    sort(all(keys)); uni(keys);

    map<ll,vector<ll>> xs[4];
    rep(i,N){
      xs[K[i]][Y[i]-X[i]].push_back(X[i]);
    }

    for(ll k : keys){
      vector<ll> nids[4];
      rep(dir,4){
        vector<ll> tmp=xs[dir][k];
        sort(all(tmp));
        nids[dir]=tmp;
      }

      rep(i,nids[1].size()){
        ll x=nids[1][i];
        auto it=lower_bound(all(nids[2]),x);
        if(it==nids[2].end())continue;
        minch(res,(*it-x)*10);
      }
      rep(i,nids[0].size()){
        ll x=nids[0][i];
        auto it=lower_bound(all(nids[3]),x);
        if(it==nids[3].end())continue;
        minch(res,(*it-x)*10);
      }
    }
  }

  {
    vector<ll> keys;
    rep(i,N){
      keys.push_back(Y[i]+X[i]);
    }
    sort(all(keys)); uni(keys);

    map<ll,vector<ll>> xs[4];
    rep(i,N){
      xs[K[i]][Y[i]+X[i]].push_back(X[i]);
    }

    for(ll k : keys){
      vector<ll> nids[4];
      rep(dir,4){
        vector<ll> tmp=xs[dir][k];
        sort(all(tmp));
        nids[dir]=tmp;
      }

      rep(i,nids[0].size()){
        ll x=nids[0][i];
        auto it=lower_bound(all(nids[1]),x);
        if(it==nids[1].end())continue;
        minch(res,(*it-x)*10);
      }
      rep(i,nids[3].size()){
        ll x=nids[3][i];
        auto it=lower_bound(all(nids[2]),x);
        if(it==nids[2].end())continue;
        minch(res,(*it-x)*10);
      }
    }
  }

  {
    vector<ll> keys;
    rep(i,N){
      keys.push_back(X[i]);
    }
    sort(all(keys)); uni(keys);

    map<ll,vector<ll>> xs[4];
    rep(i,N){
      xs[K[i]][X[i]].push_back(Y[i]);
    }

    for(ll k : keys){
      vector<ll> nids[4];
      rep(dir,4){
        vector<ll> tmp=xs[dir][k];
        sort(all(tmp));
        nids[dir]=tmp;
      }

      rep(i,nids[1].size()){
        ll x=nids[1][i];
        auto it=lower_bound(all(nids[3]),x);
        if(it==nids[3].end())continue;
        minch(res,(*it-x)*5);
      }
    }
  }

  {
    vector<ll> keys;
    rep(i,N){
      keys.push_back(Y[i]);
    }
    sort(all(keys)); uni(keys);

    map<ll,vector<ll>> xs[4];
    rep(i,N){
      xs[K[i]][Y[i]].push_back(X[i]);
    }

    for(ll k : keys){
      vector<ll> nids[4];
      rep(dir,4){
        vector<ll> tmp=xs[dir][k];
        sort(all(tmp));
        nids[dir]=tmp;
      }

      rep(i,nids[0].size()){
        ll x=nids[0][i];
        auto it=lower_bound(all(nids[2]),x);
        if(it==nids[2].end())continue;
        minch(res,(*it-x)*5);
      }
    }
  }

  if(res==INF)cout<<"SAFE"<<endl;
  else cout<<res<<endl;
  return 0;
}

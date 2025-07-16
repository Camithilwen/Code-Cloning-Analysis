#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
using uif=uint_fast64_t;
using ll=long long int;

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll uf[100000];

struct edge{int u,v,cost;};

bool comp(const edge& e1,const edge& e2){
  return e1.cost < e2.cost;
}

ll root(ll i){
  if( uf[i] == i ) return i;
  else{
    ll t=root(uf[i]);
    uf[i] = t;
    return uf[i];
  }
}

bool same(ll x,ll y){
  return root(x) == root(y);
}

void unite(ll x,ll y){
  ll x_r=root(x);
  ll y_r=root(y);
  if(x_r == y_r) return;
  uf[x_r] = uf[y_r];
}

int main(void){

  ll n;
  cin>>n;
  vector<ll> x(n);
  vector<ll> y(n);
  vector< pair<ll,ll> > p_x(n);
  vector< pair<ll,ll> > p_y(n);
  vector<ll> mincost(n);
  vector<bool> used(n);
  vector<edge> es(0);


  rep(i,n){
    cin>>x[i];
    cin>>y[i];
    pair<ll,ll> p;
    p.first=x[i];
    p.second=i;
    p_x[i]=p;
    p.first=y[i];
    p_y[i]=p;
    mincost[i] = INF;
    used[i] = false;
    uf[i]=i; // UnionFind init
  }
  mincost[0]=0;
  ll ans=0;
  sort(all(p_x));
  sort(all(p_y));
  /*
  rep(i,n){
    cout << p_x[i].first << "," << p_x[i].second << endl;
  }
  cout << endl;
  rep(i,n){
    cout << p_y[i].first << "," << p_y[i].second << endl;
  }
  */
  rep(i,n){
    if(i==0) continue;
    edge e;
    e.u=p_x[i-1].second;
    e.v=p_x[i].second;
    e.cost=min(abs(x[e.u]-x[e.v]),abs(y[e.u]-y[e.v]));
    es.pb(e);
    e.u=p_y[i-1].second;
    e.v=p_y[i].second;
    e.cost=min(abs(x[e.u]-x[e.v]),abs(y[e.u]-y[e.v]));
    es.pb(e);
  }
  sort(all(es),comp);
  for(auto e:es){
    //cout << e.u << "," << e.v << "," << e.cost << endl;
    if(!same(e.u,e.v)){
      unite(e.u,e.v);
      //cout << "unite!"<< endl;
      ans+=e.cost;
    }
  }
  /*
  while(true){
    ll v=-1;
    rep(u,n){
      if(!used[u] && (v==-1 || mincost[u] < mincost[v])){
        v=u;
        //cout << "v update into " << v << endl;
      }
    }
    if(v == -1){
      //cout << "break!" << endl;
      break;
    }
    used[v]=true;
    //cout << v << ":" << mincost[v] << endl;
    ans+=mincost[v];

    rep(u,n){
      if(u==v) continue;
      mincost[u] = min(mincost[u], min(abs(x[u]-x[v]),abs(y[u]-y[v])) );
    }

  }
  */

  cout << ans << endl;

  return 0;
}

#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 10000000

using namespace std;

int main(){
  int n,u,v; cin>>n>>u>>v; u--; v--;
  vector<vector<pi>> g( n, vector<pi>() );
  rep(i, n-1){
    int a,b; cin>>a>>b; a--; b--;
    g[a].push_back( {1,b} );
    g[b].push_back( {1,a} );
  }

  if(g[u].size()==1 && g[u][0].second==v) { cout<<0<<endl; return 0; }

  set<int>s;
  vector<int>d(n);
  rep(i, n)d[i]=INF; 
  d[u]=0;

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push( {0, u} );
  while( pq.size() ){
    auto cn = pq.top(); pq.pop();
    if(d[cn.second] < cn.first)continue;
    for(auto nn :g[cn.second]){
      if(cn.first+1 >= d[nn.second] || nn.second==v)continue;

      d[nn.second]=cn.first+1;
      pq.push( {d[nn.second], nn.second} );
    }
  }

  rep(i, n)if(d[i]!=INF)s.insert(i);
  s.insert(v);

  vector<int>d2(d);
  rep(i, n)d[i]=INF; 
  d[v]=0;
  pq.push( {0, v} );
 
  while( pq.size() ){
    auto cn = pq.top(); pq.pop();
    if(d[cn.second] < cn.first)continue;

    for(auto nn :g[cn.second]){
      if(cn.first+1 >= d[nn.second] || s.count(nn.second)==0 )continue;

      d[nn.second]=cn.first+1;
      pq.push( {d[nn.second], nn.second} );
    }
  }

//for(auto t: d2)cout<<t<<' ';cout<<endl;
//for(auto t: d)cout<<t<<' ';cout<<endl;

bool f=true;
rep(i, n)if((d[i]==1 || d2[i]==1) && d[i]!=d2[i])f=false;
if(f) { cout<<1<<endl; return 0; }

  int result=0;
  rep(i, n)if(d[i]!=INF && d2[i]!=INF){
    if(d[i]<=d2[i])continue;
    result = max(result, d[i]-1);
  }

  cout<<result<<endl;

  return 0;
}
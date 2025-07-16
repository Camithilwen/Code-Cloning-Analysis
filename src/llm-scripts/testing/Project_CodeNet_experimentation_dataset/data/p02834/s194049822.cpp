#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,u,v; cin >> n >> u >> v; u--; v--;
  vector<vector<ll>> G(n);
  rep(i,n-1){
    ll a,b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b); G[b].push_back(a);
  }
  queue<ll> q;
  q.push(u);
  vector<ll> d_u(n, 100000000);
  d_u[u] = 0;
  while(!q.empty()){
    ll now = q.front(); q.pop();
    for(ll next:G[now]){
      if(d_u[next] !=  100000000) continue;
      d_u[next] = d_u[now] + 1;
      q.push(next);
    }
  }
  q.push(v);
  vector<ll> d_v(n, 100000000);
  d_v[v] = 0;;
  while(!q.empty()){
    ll now = q.front(); q.pop();
    for(ll next:G[now]){
      if(d_v[next] !=  100000000) continue;
      d_v[next] = d_v[now] + 1;
      q.push(next);
    }
  }
  ll ans = 0;
  rep(i,n){
    if(d_u[i] < d_v[i]) ans = max(ans,d_v[i]-1);
  }
  cout << ans;

  return 0;
}
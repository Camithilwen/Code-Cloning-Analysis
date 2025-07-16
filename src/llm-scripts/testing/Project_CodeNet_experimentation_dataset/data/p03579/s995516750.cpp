#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

// 二部グラフ判定
vector<ll> color;
bool dfs(mat G,ll v,ll cur = 0) {
  color[v] = cur;
  for(auto next_v : G[v]) {
    // 隣接頂点がすでに色確定していた場合
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false; // 同じ色が隣接したらダメ
      continue;
    }

    // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
    if (!dfs(G, next_v , 1 - cur)) return false;
  }
  return true;
}

int main(){

  ll n,m;
  cin >> n >> m;

  mat G(n);
  vec a(m),b(m);
  for(ll i=0;i<m;i++){
    cin >> a[i] >> b[i];
    G[a[i]-1].push_back(b[i]-1);
    G[b[i]-1].push_back(a[i]-1);
  }
  
  vec d(n,-1);
  d[0]=0;
  queue<ll> q;
  q.push(0);
  while(!q.empty()){
    ll v=q.front();
    q.pop();
    for(ll i=0;i<G[v].size();i++){
      if(d[G[v][i]]!=-1)continue;
      d[G[v][i]]=d[v]+1;
      q.push(G[v][i]);
    }
  }
  bool ok=true;
  for(ll i=0;i<m;i++){
    if((d[a[i]-1]-d[b[i]-1])%2==0)ok=false;
  }

  color=vec(n,-1);
  if(!ok){
    cout << n*(n-1)/2-m << endl;
  }
  else{
    ll b=0;
    for(ll i=0;i<n;i++)b+=(d[i]&1);
    cout << b*(n-b)-m << endl;
  }


}
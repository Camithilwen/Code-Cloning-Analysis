#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
*/

ll N, M;
vector<ll> g[MAX];
ll clr[MAX];

void dfs(ll c, ll u) {
  if(clr[u]!=-1) return;
  
  clr[u]=c;
  
  for(ll i=0; i<g[u].size(); i++)
    dfs(1-c, g[u][i]);
    
}

int main(void) {
  ll i, j, k;
  
  cin >> N >> M;
  
  
  for(i=0; i<M; i++) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  memset(clr, -1, sizeof(clr));
  dfs(0, 0);
  
  
  for(i=0; i<N; i++) {
    for(j=0; j<g[i].size(); j++) {
      if(clr[i]==clr[g[i][j]]) { //not bipartite graph
        pt(N*(N-1)/2-M);
        return 0;
      }
    }
  }
  
  ll cnt=0;
  for(i=0; i<N; i++) if(clr[i]==0) cnt++;
  pt(cnt*(N-cnt)-M);
  
}


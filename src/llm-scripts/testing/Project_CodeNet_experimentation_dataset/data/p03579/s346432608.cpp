#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

vector<vector<int> > to;
int color[100010];
bool isbi=true;
void dfs(int v,int c=0){
  color[v]=c;
  rep(i,to[v].size()){
    int nv=to[v][i];
    if(color[nv]==-1) dfs(nv,1-c);
    else if(color[nv]==1-c) continue;
    else isbi=false;
  }
}

int main(){
  ll N,M;
  cin >> N >> M;
  to.resize(N);
  rep(i,N) color[i]=-1;
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs(0);
  ll ans;
  if(isbi){
    ll b=0,w=0;
    rep(i,N){
      if(color[i]==0) b++;
      else w++;
    }
    ans=b*w-M;
  }
  else{
    ans=N*(N-1)/2-M;
  }
  cout << ans << endl;
}
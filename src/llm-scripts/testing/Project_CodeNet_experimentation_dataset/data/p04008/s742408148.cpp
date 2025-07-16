#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int N, K;
int parent[100005];
int doub[32][100005];
int depth[100005];
int ok[100005];
vector<vector<int> > edge(100005);

void prepare() {
  for(ll i=0;i<N;++i) {
    doub[0][i] = parent[i];
  }
  for(ll i=1;i<32;++i) {
    for(ll j=0;j<N;++j) {
      doub[i][j] = doub[i-1][doub[i-1][j]];
    }
  }
}

void getdepth(ll u, ll dist) {
  depth[u] = dist;
  for(ll i=0;i<edge[u].size();++i) {
    getdepth(edge[u][i], dist+1);
  }
  return;
}

void getok(ll u) {
  if(ok[u]) return;
  ok[u] = true;
  for(ll i=0;i<edge[u].size();++i) {
    getok(edge[u][i]);
  }
  return;
}

ll getcut(ll u) {
  ll h=K-1;
  ll two;
  ll ans=u;
  ll tmp;
  while(h>0) {
    two = 1;
    tmp = 0;
    while(2*two<h) {
      two *= 2;
      tmp++;
    }
    h -= two;
    ans = doub[tmp][ans];
  }
  return ans;
}

int main() {
  cin>>N>>K;
  ll tmp;
  ll ans = 0;
  for(ll i=0;i<N;++i) {
    cin>>tmp;
    tmp--;
    if(i==0 && tmp!=0) ans++;
    if(i!=0) {
      parent[i] = tmp;
      edge[tmp].push_back(i);
    }
  }
  prepare();
  /**
  for(ll i=0;i<10;++i) {
    for(ll j=0;j<N;++j) {
      cout<<doub[i][j]<<" ";
    }
    cout<<endl;
  }
  **/
  getdepth(0, 0);
  vector<pair<ll, ll> > arr(N);
  for(ll i=0;i<N;++i) arr[i] = mp(depth[i], i);
  sort(arr.begin(), arr.end(), greater<pair<ll, ll> >());
  ll cut;
  for(ll i=0;i<N;++i) {
    if(ok[arr[i].se]) continue;
    if(arr[i].fi<=K) continue;
    ans++;
    cut = getcut(arr[i].se);
    getok(cut);
  }
  cout<<ans<<endl;
}



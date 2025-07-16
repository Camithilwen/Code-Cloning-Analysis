#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

int n,m;
const int maxM = 202020;
const int INF = 1e9;
vector<PII> edge[3*maxM];
map<PII, int> sid;
int lastId = 0;

// 頂点と色を引数に持って新しく追加する頂点との間にエッジを張る
// 今まで出てきた端点と同じものがあったら同じグループに追加する
int getid(int v, int c){
  PII p(v,c);
  if( sid.find(p) !=  sid.end()) return sid[p];
  return sid[p] = lastId++;
}

void addEdge(int a, int b, int c){
  // 同じ辺の要素はコスト0の辺を貼ったのでそれぞれの端点で独立に考える
  int v = getid(a,c), u = getid(b,c);
  edge[v].emplace_back(u,0);
  edge[u].emplace_back(v,0);
}

void dijkstra(){
  int dist[n + lastId];
  rep(i,n+lastId) dist[i] = INF;
  dist[lastId] = 0;
  priority_queue< PII, vector<PII>, greater<PII>> que;
  que.push({0,lastId});
  while(que.empty() == false){
    PII p = que.top(); que.pop();
    int cdist = p.first, current = p.second;

    if(dist[current] < cdist) continue;

    for(PII e: edge[current]){
      if(dist[e.first] > cdist + e.second){
          que.push({cdist + e.second,e.first});
          dist[e.first] = e.second + cdist;
      }
    }
  }

  if(dist[lastId+n-1] == INF){
    cout << -1 << endl;
    return;
  }else cout << dist[lastId+n-1]/2 << endl;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;

  int a[m],b[m],c[m];

  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--,b[i]--;
    addEdge(a[i],b[i],c[i]);
  }

  // 作成した頂点と入力の辺の端点からコスト1の辺を張る
  rep(i,m){
    edge[getid(a[i], c[i])].emplace_back(lastId+a[i], 1);
    edge[getid(b[i], c[i])].emplace_back(lastId+b[i], 1);
    edge[lastId+a[i]].emplace_back(getid(a[i], c[i]), 1);
    edge[lastId+b[i]].emplace_back(getid(b[i], c[i]), 1);
  }

  dijkstra();
  return 0;
}

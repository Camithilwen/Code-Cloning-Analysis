#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);
    vector<ll> D(N);

    REP(i, N){
        cin >> A[i] >> B[i];
    }
    REP(i, N){
        cin >> C[i] >> D[i];
    }

    BipartiteMatching bm(N + N);

    REP(i, N){
        REP(j, N){
            // cout << i << " " << j << endl;
            if((A[i] < C[j]) && (B[i] < D[j])){
                bm.add_edge(i, N + j);
                // cout << i << " " << j << endl;
            }
        }
    }

    // BipartiteMatching bm(X + Y);
    // for(int i = 0; i < E; i++) {
    //     int a, b;
    //     cin >> a >> b;
    //     bm.add_edge(a, X + b);
    // }

    cout << bm.bipartite_matching() << endl;
    return 0;
}
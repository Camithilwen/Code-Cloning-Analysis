#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




//—————————————————BFSグラフ————————————————

using Graph = vector<vector<pair<ll,ll>>>;

int main() {
    // 頂点数と辺数
    ll n;
    cin >> n;


    // グラフ入力受取
    Graph G(n);
    rep(i,n-1) {
        ll a,b,c;
        cin >> a >> b >> c;
        auto x=mp(b-1,c);
        G[a-1].pb(x);
        auto y=mp(a-1,c);
        G[b-1].pb(y);
    }

    ll q,k;
    cin>>q>>k;
    k--;

    // BFS のためのデータ構造
    vector<ll> dist(n, 1000000000000000000); // 全頂点を「未訪問」に初期化
    deque<ll> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[k] = 0;
    que.pb(k); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        ll v = que.front(); // キューから先頭頂点を取り出す
        que.pop_front();

        // v から辿れる頂点をすべて調べる
        for (auto nv : G[v]) {
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            if(dist[nv.fi]>dist[v] + nv.se){
            dist[nv.fi] = dist[v] + nv.se;
            que.pb(nv.fi);
            }
        }
    }

  rep(i,q){
    ll x,y;
    cin>>x>>y;
    cout << dist[x-1]+dist[y-1] << endl;
  }

}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい
	}

	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}

		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};
//UnionFind Uni(N);
//Uni.connect;

struct Edge
{
  int from, to, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    int min_cost = 0;

    rep(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.from, e.to)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.connect(e.from, e.to);
      }
    }

    return min_cost;
  }
};

// 標準入力からグラフを読み込む
Graph input_graph() {
  Graph g;
  int m;
  cin >> g.n >> m;
  rep(i, m) {
    Edge e;
    cin >> e.from >> e.to >> e.cost;
    g.es.push_back(e);
  }
  return g;
}


int main(){
  int n;
  cin >> n;
  // Graph g = input_graph();
  vector<P> xp;
  vector<P> yp;
  rep(i,n){
    int x,y;
    cin >> x >> y;
    xp.push_back(make_pair(x,i));
    yp.push_back(make_pair(y,i));
  }
  sort(xp.begin(),xp.end());
  sort(yp.begin(),yp.end());
	Graph g;
	g.n=n;
	rep(i,n-1){
		Edge e;
		e.from = xp[i].second;
		e.to = xp[i+1].second;
		e.cost = xp[i+1].first - xp[i].first;
		g.es.push_back(e);
	}
	rep(i,n-1){
		Edge e;
		e.from = yp[i].second;
		e.to = yp[i+1].second;
		e.cost = yp[i+1].first - yp[i].first;
		g.es.push_back(e);
	}
  cout << g.kruskal() << endl;
  return 0;
}

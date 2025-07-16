#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ECHO(x) cout<<x<<endl;
#define MEMSET(a, n, x) REP(i, n) a[i]=x;
#define ARRIN(a, n) REP(i, n) cin>>a[i];
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;

class unionfind{
  public:
  int Num;
  vector<int> par; //親の番号
  vector<int> height; //木の高さ(ランク)

  unionfind(int N):
    par(vector<int>(N, 0)), height(vector<int>(N, 0)), Num(N) {}


  //初期化
  void init(){
    REP(i, Num){
      par[i] = i;
      height[i] = 0;
    }
  }

  //xの親番号を返す、再帰処理あり
  int root(int x){
    return par[x] == x ? x : par[x] = root(par[x]);
  }

  //xとyの親番号が同一か判定する
  bool same(int x, int y){
    return root(x) == root(y);
  }

  //xとyのある木を結合する
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return; //親が同一なら結合済み。

    if(height[x] < height[y]) par[x] = y;
    else {
      par[y] = x;
      if(height[x] == height[y]) height[x]++;
    }
  }
};

int main(){
  int n, k, l;
  cin>>n>>k>>l;
  unionfind ro(n);
  unionfind ra(n);
  map<P, LL> mp;
  ro.init();
  ra.init();
  LL ans, r;
  int t1, t2;
  REP(i, k){
    cin>>t1>>t2;
    --t1;
    --t2;
    ro.unite(t1, t2);
  }

  REP(i, l){
    cin>>t1>>t2;
    --t1;
    --t2;
    ra.unite(t1, t2);
  }

  REP(i, n){
    ++mp[make_pair(ro.root(i), ra.root(i))];
  }
  REP(i, n){
    r=mp[make_pair(ro.root(i), ra.root(i))];
    ECHO(r);
  }
  return 0;
}

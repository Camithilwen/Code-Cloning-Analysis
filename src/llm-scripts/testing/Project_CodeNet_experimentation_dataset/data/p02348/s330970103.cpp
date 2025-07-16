#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
//区間加算　区間和クエリ
//演算の定義
auto query = [](ll x, ll y) { return x+y; };
//単位元
const ll unit = 0;
struct LazySegTree
{
private:
  ll n;
  vector<ll> node,lazy;

public:
  LazySegTree(vector<ll> v)
  {
    node.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1, unit); 
    lazy.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1,-1); 
    n = 1LL << 64 - __builtin_clzll(v.size());
    for (ll i = 0; i < v.size(); i++)
      node[i + n - 1] = v[i]; //最下段から構築
    for (ll i = n - 2; i >= 0; i--)
      node[i] = query(node[2 * i + 1], node[2 * i + 2]);
  }
  
  // k 番目のノードについて遅延評価を行う
  void eval(int k, int l, int r){ 
    // 遅延配列が空でない場合、自ノード及び子ノードへの
    // 値の伝播が起こる
    if (lazy[k] != -1){
      node[k] = lazy[k];
      // 最下段かどうかのチェックをしよう
      // 子ノードは親ノードの 1/2 の範囲であるため、
      // 伝播させるときは半分にする
      if (r - l > 1){
        lazy[2 * k + 1] = lazy[k] / 2;
        lazy[2 * k + 2] = lazy[k] / 2;
      }
      // 伝播が終わったので、自ノードの遅延配列を空にする
      lazy[k] = -1;
    }
  }

  void update(int a, int b, ll x, int k = 0, int l = 0, int r = -1){
    if (r < 0)
      r = n;
    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);
    // 範囲外なら何もしない
    if (b <= l || r <= a)
      return;
    // 完全に被覆しているならば、遅延配列に値を入れた後に評価
    if (a <= l && r <= b){
      lazy[k]= (r - l) * x;
      eval(k, l, r);
    }
    // そうでないならば、子ノードの値を再帰的に計算して、
    // 計算済みの値をもらってくる
    else{
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  // 要求区間 [a, b) 中の要素の和を答える k := 自分がいるノードのインデックス 対象区間は [l, r) にあたる
  ll get(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
  {
    // 最初に呼び出されたときの対象区間は [0, n)
    if (r < 0)
      r = n;
    // 要求区間と対象区間が交わらない -> 適当に返す
    if (r <= a || b <= l)
      return unit;
    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    // 関数が呼び出されたら評価！
    eval(k, l, r);
    if (a <= l && r <= b)
      return node[k];
    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
    return query(vl, vr);
  }
};

int main()
{
ll n , q ;
cin >> n >> q ;

vector<ll> t(n,(1LL<<31)-1);
LazySegTree s(t);
vector<ll> ans;
rep(i,q){
  ll a  ;
  cin >> a  ;
  if(!a){
    ll b , c , d ;
    cin >> b >> c >> d ;
    s.update(b, c+1, d);
  }
  else {
    ll b ;
    cin >> b ;
    ans.push_back(s.get(b, b+1));
  }
}

rep(i,ans.size())cout<<ans[i]<<"\n";

return 0;
}


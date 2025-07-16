#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 9000000000000000000 //9e18:極めて大きい値
#define MOD 998244353
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
#define LOGMAXR 18 // floor(log2(10^5)) + 1: 配列の最大のrangeのlog
//略記
//#define PB push_back //vectorヘの挿入
//#define MP make_pair //pairのコンストラクタ
//#define F first //pairの一つ目の要素
//#define S second //pairの二つ目の要素

ll modpow(ll n, ll p){
  ll ret = 1;
  while(p){
    if(p & 1){
      ret *= n;
      ret %= MOD;
    }
    p >>= 1;
    n = n * n;
    n %= MOD;
  }
  return ret;
}

map<ll, ll> modinv_memo;
ll modinv(ll n) {
  if(modinv_memo.count(n)) return modinv_memo[n];
  // ll b = MOD, u = 1, v = 0;
  // while (b) {
  //   ll t = n / b;
  //   n -= t * b; swap(n, b);
  //   u -= t * v; swap(u, v);
  // }
  // u %= MOD;
  // if (u < 0) u += MOD;
  //modinv_memo[n] = u;
  ll ret = modpow(n, MOD-2);
  modinv_memo[n] = ret;
  return ret;
}


int main(){
  ll N, M, K;
  cin >> N >> M >> K;
  if(M == 1){
    if(K == N - 1){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return 0;
  }
  ll ret = 0;
  ll it = (M * modpow(M - 1, N - 1)) % MOD;
  REP(k, K + 1){
    ret += it;
    ret %= MOD;
    it *= modinv(k + 1);
    it %= MOD;
    it *= (N - 1 - k);
    it %= MOD;
    it *= modinv(M - 1);
    it %= MOD;
  }
  cout << ret << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;
typedef int64_t ll;
typedef uint64_t ull;

#define INF LLONG_MAX

#define FOR(i, start, end) for(uint64_t i=start; i<end; i++)
#define REP(i, n) FOR(i, 0, n)

// 最大公約数gcd
// 最小公倍数lcm=m*n/gcd
uint64_t gcd(uint64_t m, uint64_t n) {
  uint64_t temp;
  while (m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

uint64_t lcm(uint64_t m, uint64_t n) {
  return (m*n)/gcd(m,n);
}

// vector<vector<uint64_t> > v(n+1, vector<uint64_t>(n+1, 0))
// v[n][k]に組み合わせ数が入る。
void comb(vector<vector <uint64_t> > &v){
  for(uint64_t i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(uint64_t k = 1;k <v.size();k++){
    for(uint64_t j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

// 掛け算オーバーフロー判定
bool is_product_overflow(uint64_t a, uint64_t b) {

	uint64_t prod = a * b;
	
	return (prod / b != a);
}

//素因数分解
void primeFactorization(uint64_t a, list<uint64_t> &factors){ //素因数分解を出力するプログラム
  long i,sq;
  if(a%2==0){ //偶数の場合
    factors.push_back(2);
    primeFactorization(a/2,factors); //2で割った値で再帰
    return;
  }
  sq = sqrt(a);
  for(i=3;i<=sq;i+=2){ //3以上√a以下の奇数の場合
	if(a%i==0){
	  factors.push_back(i);
      primeFactorization(a/i,factors); //割れた値で再帰
      return;
	}
  }
  //偶数でも3以上√a以下の奇数の場合でも割り切れない場合
  if(a!=1){ //aが1でないなら、a自身は素数
    factors.push_back(a);
  }
}

// フェルマーの小定理
// mod. m での a の逆元 a^{-1} を計算する
// (a/b)%m = a*movinv(b,m)%m  
int64_t modinv(int64_t a, int64_t m) {
    int64_t b = m, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// 円周率
// M_PI

// #include <iomanip> // setprecisionを使用するのに必要
// cout << std::fixed << std::setprecision(15) << y << endl;

// 昇順
// priority_queue<int, vector<int>, greater<int> > queue;

signed main() {
  int h,w;
  cin >> h >> w;
  
  vector<string> grid(h, "");
  int whiteCount = 0;
  for(int i=0;i<h;i++){
    cin >> grid[i];
    for(auto c:grid[i]){
      if(c=='.')whiteCount++;
    }
  }
  
  queue<tuple<int,int,int>> q;
  q.emplace(0,0,0);
  grid[0][0] = 'x';
  while(!q.empty()){
    auto pos = q.front();q.pop();
    if(get<0>(pos)==h-1&&get<1>(pos)==w-1){
      cout << whiteCount-1-get<2>(pos) << endl;     
      return 0;
    }
    if(get<0>(pos)>0 && grid[get<0>(pos)-1][get<1>(pos)]=='.'){
      q.emplace(get<0>(pos)-1,get<1>(pos),get<2>(pos)+1);
      grid[get<0>(pos)-1][get<1>(pos)] = 'x';
    }
    if(get<0>(pos)<h-1 && grid[get<0>(pos)+1][get<1>(pos)]=='.'){
      q.emplace(get<0>(pos)+1,get<1>(pos),get<2>(pos)+1);
      grid[get<0>(pos)+1][get<1>(pos)] = 'x';
    }
    if(get<1>(pos)>0 && grid[get<0>(pos)][get<1>(pos)-1]=='.'){
      q.emplace(get<0>(pos),get<1>(pos)-1,get<2>(pos)+1);
      grid[get<0>(pos)][get<1>(pos)-1] = 'x';
    }
    if(get<1>(pos)<w-1 && grid[get<0>(pos)][get<1>(pos)+1]=='.'){
      q.emplace(get<0>(pos),get<1>(pos)+1,get<2>(pos)+1);
      grid[get<0>(pos)][get<1>(pos)+1] = 'x';
    }
  }
  cout << "-1" << endl;
  return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;
typedef int64_t ll;
typedef uint64_t ull;

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

ll pCount(int x){
  if(x==0) return 1;
  return pCount(x-1)*2 + 1;
}

ll allCount(int x){
  if(x==0) return 1;
  return allCount(x-1)*2 + 3;
}


signed main() {
  int n,k;
  cin >> n >> k;
  k--;
  vector<int> pos(n);
  for(int i=0;i<n;i++){
    cin >> pos[i];
  }
  
  int minDist = 1000000000;
  for(int i=0;i<n-k;i++){
    if((pos[i]<=0 && pos[i+k]<=0)
      ||(pos[i]>=0 && pos[i+k]>=0)){
      minDist = min(minDist, (abs(pos[i])>abs(pos[i+k]))?abs(pos[i]):abs(pos[i+k]));
    }
    else if(pos[i]<=0 && pos[i+k]>=0){
      if(abs(pos[i]) < pos[i+k]){
        minDist = min(minDist, abs(pos[i])*2+pos[i+k]);
      }
      else{
        minDist = min(minDist, pos[i+k]*2+abs(pos[i]));
      }
    }
  }
  
  cout << minDist << endl;
  
  
  return 0;
}


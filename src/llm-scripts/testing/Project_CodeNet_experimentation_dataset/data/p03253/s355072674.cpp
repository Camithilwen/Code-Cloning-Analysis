#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF const ll INF = 1001001001;
#define PI const ld PI = 3.14159265358979323846;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<vector<long long>> comb(int n, int r) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  ll div=(ll)powl(10,9)+7;
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k])%div;
    }
  }
  return v;
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll N,M;
    cin >> N>>M;
    //pairの書き換えが煩雑であるので、素数リストと指数連想配列に分ける
   map<ll,ll> prime_count;
   vector<ll> prime_list;
   
    //resに素数のペア(素数、その素数の指数）の配列が入る
    const auto  &res = prime_factorize(M);
    
   rep(i,res.size()){
       if(prime_count[res[i].first]==0){
           prime_list.push_back(res[i].first);
       }
       prime_count[res[i].first]+=res[i].second;
   }
   // 前処理
    COMinit();
    

    ll ans=1;
    rep(i,prime_list.size()){
        ans*=COM(N+prime_count[prime_list[i]]-1,N-1);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
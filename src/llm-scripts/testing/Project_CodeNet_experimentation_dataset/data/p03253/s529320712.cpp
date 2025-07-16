#include<bits/stdc++.h>
using namespace std;

//mod逆元を使ったnCkの計算(速)
const int64_t MAX = 510000;
const int64_t MOD = 1000000007;

int64_t fac[MAX], finv[MAX], inv[MAX];

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
int64_t COM(int64_t n, int64_t k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {

    // input from txt （提出時にこの箇所は削除すること）
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    int64_t N, M;
    cin >> N >> M;
    COMinit();
    
    int64_t n = M;
    
    //素因数分解
    map<int64_t,int64_t> mp;
    int a = 2;
    while(n >= a*a){
      if(n %a == 0){
        if(mp.count(a)){
          mp[a]++;
        }
        else{
          mp[a] = 1;
        }
        n /= a;
      }
      else{
        a++;
      }
    }
    if(mp.count(n)){
      mp[n]++;
    }
    else{
      mp[n] = 1;
    }
    
    int64_t ans = 1;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        int64_t x = itr->second;
        //cout << x << endl;
        ans *= COM(x+N-1,N-1);
        ans %= MOD;
    }
    if(M == 1){
        ans = 1;
    }
    
    cout << ans << endl;
    
}
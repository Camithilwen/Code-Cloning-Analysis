#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int64_t expotent(int64_t n,int64_t m){
  if (m == 1) return n;
  else if (m % 2 == 0) return expotent(n * n % MOD, m/2);
  else return expotent(n * n % MOD, m/2) * n % MOD;
}

int64_t nCr(int64_t n, int64_t r){
  int Ans = 1;  
  if (r > n / 2) r = n - r;
  for (int i = 1; i <= r; i++)
    Ans = Ans * (n + 1 - i) % MOD * expotent(i, MOD-2) %MOD;
  
  return Ans;
}

int main(){
  int64_t H, W, A, B;
  int64_t currentways = 1;
  int64_t ways = 0;
  
  cin >> H >> W >> A >> B;

  currentways = nCr(H+W-B-2, W-B-1);
  ways += currentways;
  for (int i = 1; i < H-A; i++){
    //ways += nCr(i+B-2, B-1) * nCr(H+W-i-B-1, W-B-1);  
    currentways = currentways * (i+B-1) % MOD * expotent(i, MOD-2) % MOD * (H-i) % MOD * expotent(H+W-i-B-1, MOD-2) %MOD;
    ways =(ways + currentways) % MOD;
  }
  
  cout << ways;
}
#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long n){
  if(n == 1) return false;
  for(long long i = 2; i * i < n; i++){
    if(n%i == 0) return false;
  }
  return true;
}

vector<pair<long long, long long>> PrimeFactorize(long long n){
  vector<pair<long long, long long>> res;

  long long a = 0;

  for(long long i = 2; i * i <= n; i++){
    a = 0;
    if(n%i == 0){
      if(IsPrime(i)){
        while(n % i == 0){
          n /= i;
          a++;
        }
        res.push_back(make_pair(i, a));
      }
    }
  }

  if(n!= 1) res.push_back(make_pair(n, 1));
  return res;
}

int NumOfDivisor(long long n){
  vector<pair<long long, long long>> res;
  res = PrimeFactorize(n);

  int num = 1;
  for(int i = 0; i < res.size(); i++){
    num *= (1 + res[i].second);
  }

  return num;

}

int main(){
  const int mod = 1e9 + 7;
  int n;
  const int max_n = 1e3;
  cin >> n;

  long long ans = 1;
  long long ex[max_n + 2]  = {};
  
  for(int i = 1; i <= n; i++){
    vector<pair<long long, long long>> res;
    res = PrimeFactorize(i);
    for(int j = 0; j < res.size(); j++){
      ex[res[j].first - 1] += res[j].second;
    }
  }

  for(int i = 0; i < n; i++){
    ans *= (ex[i] + 1);
    ans %= mod;
  }

  cout << ans << endl;


  return 0;
}
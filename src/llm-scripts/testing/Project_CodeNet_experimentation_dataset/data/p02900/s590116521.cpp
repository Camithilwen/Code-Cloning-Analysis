#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

long long gcd(long long x, long long y){
  if(y == 0) return x;
  else return gcd(y, x%y);
}

bool IsPrime(long long n){
  if(n == 1) return false;
  for(long long i = 2; i * i < n; i++){
    if(n%i == 0) return false;
  }
  return true;
}

vector<long long> EnumDivisors(long long n){
  vector<long long> res;

  for(long long i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(n/i != i) res.push_back(n/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

vector<pair<long long, long long>> PrimeFactorize(long long n){
  vector<pair<long long, long long>> res;

  long long a = 0;
  long long b = 0;

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

int main(){
  long long a, b;
  cin >> a >> b;

  vector<pair<long long, long long>> a_fac = PrimeFactorize(a);
  vector<pair<long long, long long>> b_fac = PrimeFactorize(b);

  // for(int i = 0; i < a_fac.size(); i++) cout << a_fac[i].first << ", " << a_fac[i].second << endl;
  // for(int i = 0; i < b_fac.size(); i++) cout << b_fac[i].first << ", " << b_fac[i].second << endl;

  long long ans = 0;
  for(int i = 0; i < a_fac.size(); i++){
    for(int j = 0; j < b_fac.size(); j++){
      if(a_fac[i].first == b_fac[j].first) {
        // cout << "i = " << i << ", j = " << j << endl;
        ans ++;
      }
    }
  }
  cout << ans + 1 << endl;
  
  

  return 0;
}
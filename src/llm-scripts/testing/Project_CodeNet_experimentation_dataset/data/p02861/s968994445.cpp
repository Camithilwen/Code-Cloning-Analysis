//g++ -std=gnu++14 a.cpp

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MODP = 998244353;

ll per(ll a){
  ll res = 1;
  for(int i = 1;i <= a;i++){
    res *= i;
  }
  return res;
}

int main(){
  ll N;
  cin >> N;
  vector<long double> x(N),y(N);
  rep(i,N)cin >> x[i] >> y[i];
  vector<vector<int>> kumi;
  vector<int> v;
  for(int i = 1;i <= N;i++)v.push_back(i);
  do{
    kumi.push_back(v);
  }while(next_permutation(v.begin(), v.end()));
  long double ans = 0;
  for(auto a : kumi){
    rep(i,a.size()-1){
      long double t = (x[a[i]-1]-x[a[i+1]-1])*(x[a[i]-1]-x[a[i+1]-1]);
      t += (y[a[i]-1]-y[a[i+1]-1])*(y[a[i]-1]-y[a[i+1]-1]);
      ans += sqrt(t);
    }
  }
  long double all = kumi.size();
  ans /= all;
  cout << fixed << setprecision(8) << ans << endl;

  return 0;
}

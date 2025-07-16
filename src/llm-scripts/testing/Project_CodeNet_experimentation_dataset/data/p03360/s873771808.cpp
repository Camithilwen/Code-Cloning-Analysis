#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  vl abc(3);
  rep(i, 3) cin >> abc[i];
  ll K;
  cin >> K;

  stable_sort(abc.begin(), abc.end());

  rep(i, K) abc[2] *= 2;

  cout << abc[0] + abc[1] + abc[2] << endl;
  
  return 0;
}

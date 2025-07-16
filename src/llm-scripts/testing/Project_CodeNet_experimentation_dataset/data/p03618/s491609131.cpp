#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  string A;
  cin >> A;
  map<char, ll> z;
  for (int i=0; i<(int)A.size(); i++) {
    if (z.count(A[i])) z[A[i]]++;
    else z[A[i]] = 1;
  }
  ll num = 0;
  for (auto p: z) {
    auto value = p.second;
    num += value*(value-1)/2;
  }
  cout << (ll)A.size()*(A.size()-1)/2-num+1 << endl;
  return 0;
}
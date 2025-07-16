#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int x[10],y[10];
int n;

double f(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx*dx+dy*dy,0.5);
}

int main() {
  cin >> n;
  rep(i,n) cin >> x[i] >> y[i];

  std::vector<int> v(n);
  rep(i,n) v.at(i) = i;

  double total = 0.0;
  do {
    rep(i,n-1) total += f(v[i],v[i+1]);
  } while(next_permutation(v.begin(), v.end()));

  int num = 1;
  for (int i = 2; i <= n; i++) num *= i;
  cout << std::fixed << std::setprecision(16) << total / num << endl;
}

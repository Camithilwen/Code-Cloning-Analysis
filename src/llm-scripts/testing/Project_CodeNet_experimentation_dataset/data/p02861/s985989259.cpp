//算数的な問題　

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

int f(int n){
  if (n == 0) return 1;
  else return n * f(n - 1);
}

int main(void){
  int N;
  cin >> N;
  vector <int> x(N), y(N);
  rep(i,N) cin >> x[i] >> y[i];
  //ラムダ式
  //点iと点jの距離
  auto dist = [&](int i, int j){
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
  };

  //順列を使わない方法
  double len = 0;
  rep(i,N)rep(j,i){
    len += dist(i,j);
  }
  double ans = (len * 2) / N;

  //順列を使う方法
  // vector <int> p(N);
  // rep(i,N) p[i] = i;
  // double len = 0;  //長さ
  // int cnt = 0;
  // do {
  //   rep(i,N-1){
  //     len += dist(p[i], p[i + 1]);
  //   }
  //   cnt ++;
  // } while (next_permutation(all(p)));
  // double ans = len/cnt;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}

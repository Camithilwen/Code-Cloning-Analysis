#include <bits/stdc++.h>
#include <iomanip> // setprecision
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  // 辺を何回使うか = x
  //
  // ### 全ての辺についての x の総和
  // sigma(x)
  // 辺
  // = 辺1のx + 辺2のx + ... 辺nのx
  // = 辺の本数 * x
  // ### n 個の町から2個を選び、その間にできる辺の数を数える
  // ### n=3 の場合、3C2 = (3*2) / (2*1) = 3 で、辺の本数は3本となる
  // = nC2 * x ... (a)
  //
  // ### n=3 の場合、3点を結ぶ辺は2本になる。そのため (n-1)
  // ### 町を巡回する経路は n! = 3*2*1 = 6通りある。
  // = (n-1) * n! ... (b)
  //
  // ### (a) (b) より
  //
  // nC2 * x = (n-1) * n!
  // x = ((n-1) * n!) / nC2
  // x = ((n-1) * n!) / (n*(n-1) / (2*1))
  // x = 2((n-1) * n!) / (n*(n-1))
  // x = 2 * (n-1)!
  //
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i);
  }

  // [&] 参照キャプチャ、vectorコンテナ x, y を lambda 式内で参照している
  auto dist = [&](int i, int j) {
    double dx = x.at(i) - x.at(j);
    double dy = y.at(i) - y.at(j);
    return sqrt(dx*dx + dy*dy);
  };

  // 全パターンの辺の長さの和を求める
  double len = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      // 特定2点の辺の長さ
      len += dist(i, j);
    }
  }

  // 辺の利用回数
  int num = 2;
  for (int i = 1; i <= (n-1); i++) {
    num = num * i;
  }

  // 巡回のパターン数
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    cnt = cnt * i;
  }

  // ### 入力例1の場合
  // len = (1,2) の辺の長さ + (2,3) の辺の長さ + (3,1) の辺の長さ
  // num = 全パターンの巡回を行った際、各辺の利用回数 = 4
  // len * num = 全パターンの巡回を行った際の辺の長さの和
  //
  // cnt = 巡回のパターン数
  // (len * num) / cnt = 1パターンごとの経路の平均値
  //
  //
  // ### 経路の長さの平均値である ans を算出する数式を整理する
  //
  // x = 2 * (n-1)!
  //
  // ans = (各辺の長さの和 * 1辺ごとの利用回数) / パターン数
  //     = (sigma(len) * (2 * (n-1)!)) / n!
  //     = (sigma(len) * 2) / n
  //
  // これより、以下の式でもOK
  // double ans = (len * 2) / n;
  // これより平均値
  double ans = (len * num) / cnt;

  printf("%.10f\n", ans);
  return 0;
}

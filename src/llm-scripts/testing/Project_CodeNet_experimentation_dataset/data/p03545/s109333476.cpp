#include <bits/stdc++.h>
using namespace std;

void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

void foreach_comb(int n, int k, function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int calc(string c) {
  int ret = 0;
  char lastOp = '+';
  for (int i = 0; i < c.size(); i++) {
    if (c[i] == '+') {
      lastOp = '+';
    } else if (c[i] == '-') {
      lastOp = '-';
    } else {
      int num = atoi(c.substr(i, 1).c_str());
      if (lastOp == '+') {
        ret += num;
      } else {
        ret -= num;
      }
    }
  }
  return ret;
}

int main() {
  // 入力
  vector<char> S(4);
  for (int i = 0; i < (int)S.size(); i++)
    cin >> S.at(i);
  
  int n = S.size() - 1;
  for (int k = 0; k <= n; k++) {
    foreach_comb(n, k, [S, n, k](int *indexes) {
      vector<char> op(n);
      for (int i = 0; i < n; i++) {
        op.at(i) = '+';
      }
      for (int i = 0; i < k; i++) {
        op.at(indexes[i]) = '-';
      }
      // 一つの文字列に連結
      string c = "";
      for (int i = 0; i < S.size(); i++) {
        c += S.at(i);
        if (i < op.size()) {
          c += op.at(i);
        }
      }
      // その文字列を計算する
      int ret = calc(c);
      if (ret == 7) {
        cout << c << "=" << ret << endl;
        exit(0);
      }  
    });
  }
}

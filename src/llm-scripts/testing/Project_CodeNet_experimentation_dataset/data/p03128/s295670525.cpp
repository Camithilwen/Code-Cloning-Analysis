#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, M;
  cin >> N >> M;

  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }

  // 昇順で確認する必要がある
  sort(A.begin(), A.end());

  vector<int> p = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  // マッチをi本使ったときの桁数の最大値
  // 初期値は-1で埋めておく
  // 要素数は N + 7 (pの最大値) + α
  vector<int> dp(N+10, -1);

  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int k = p[A[j]];
      dp[i + k] = max(dp[i + k], dp[i] + 1);
    }
  }

  // 残りのマッチの本数
  int remain = N;

  while (0 < remain) {

    // 答え
    int answer = 0;

    // 使うマッチの本数
    int use = 0;
    
    for (int i = 0; i < M; i++) {

      // 使いたいマッチの本数
      int k = p[A[i]];
      
      // マッチが使える場合
      if (k <= remain) {
      
        // kを使った後の残ったマッチの本数でも桁数が最大値が作れる場合はOK
        if (dp[remain - k] == dp[remain] - 1) {
          // OK場合でもMはできる限り大きい数にする
          answer = A[i];
          use = k;
        }

      }

    }

    // マッチの数を減らす
    remain -= use;

    cout << answer;
  
  }

  cout << endl;

  return 0;

}
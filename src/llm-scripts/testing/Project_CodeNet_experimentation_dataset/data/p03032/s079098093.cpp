#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  deque<int> jewel;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    jewel.push_back(num);
  }
  int ans = -1;
  for (int i = 0; i <= min(N, K); i++) {
    for (int j = 0; j <= min(N, K)-i; j++) {
      deque<int> jewel_copy = jewel;
      vector<int> tmp;
      for (int a = 0; a < i; a++) {
        tmp.push_back(jewel_copy.front());
        jewel_copy.pop_front();
      }
      for (int b = 0; b < j; b++) {
        tmp.push_back(jewel_copy.back());
        jewel_copy.pop_back();
      }
      sort(tmp.begin(), tmp.end());
      int value = 0, trash = K - i - j;
      for (auto x : tmp) {
        if (trash > 0 && x < 0) {
          trash--;
          continue;
        }
        value += x;
      }
      if (value > ans) ans = value;
    }
  }
  cout << ans << endl;
}

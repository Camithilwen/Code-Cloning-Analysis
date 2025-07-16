#include<iostream>
#include<cmath>

using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  string ans = "-1 -1 -1";
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      int k = N - j - i;
      if (k < 0) continue;
      if (i * 10000 + j * 5000 + k * 1000 == Y) {
        ans = to_string(i) + ' ' + to_string(j) + ' ' + to_string(k);
        break;
      }
    }
    if (ans != "-1 -1 -1") break;
  }
  cout << ans << endl;
}
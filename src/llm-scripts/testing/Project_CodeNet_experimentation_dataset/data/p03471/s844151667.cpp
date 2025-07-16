#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() { 
  int N, Y;
  cin >> N >> Y;

  for (int x = 0; x <= N; x++) {
    for (int y = 0; y <= N; y++) {
      if (N - x - y < 0) continue;
      int sum = 10000 * x + 5000 * y + 1000 * (N - x - y);
      if (sum == Y){
        cout << x << " " << y << " " << N - x - y << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
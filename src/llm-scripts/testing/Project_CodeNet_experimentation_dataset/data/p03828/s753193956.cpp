#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int>so;
  vector<bool>un(N + 1, true);
  const long long mo = 1e9 + 7;
  for (int i = 2; i <= N; i ++) {
    if (un[i]) {
      so.push_back(i);
      for (int j = 0; j <= N / i; j ++) {
        un[i * j] = false;
      }
    }
  }
  long long ans = 1;
  int si = (int)so.size();
  for (int i = 0; i < si; i ++) {
    int n = N;
    long long kj = 0;
    while (n) {
      kj += (long long) n / so[i];
      n /= so[i];
      kj %= mo;
    }
    ans *= kj + 1;
    ans %= mo;
  }
  cout << ans << endl;
}


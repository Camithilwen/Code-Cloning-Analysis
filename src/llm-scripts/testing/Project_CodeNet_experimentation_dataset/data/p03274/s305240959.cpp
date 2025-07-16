#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, K;
  cin >> N >> K;
  vector<int>pl;
  vector<int>mn;
  pl.push_back(0);
  mn.push_back(0);
  for (int i = 0; i < N; i ++) {
    int a;
    cin >> a;
    if (a < 0) mn.push_back(-a);
    else pl.push_back(a);
  }
  int kj = min((int)mn.size(), K + 1);
  int n = (int)mn.size();
  sort(mn.begin(), mn.end());
  int m = (int)pl.size();
  int ans = 1e9;
  for (int i = 0; i < kj; i ++) {
    int j = K - i;
    if (j < m) ans = min(ans, min((pl[j] * 2) + mn[i], pl[j] + (mn[i] * 2)));
  }
  cout << ans << endl;
}


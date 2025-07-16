#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, string s) {
  vector<int> w(n, 0), e(n, 0);
  if(s[0] == 'W') {
    w[0] = 1;
  } else {
    e[0] = 1;
  }
  for(int i=1;i<n;i++) {
    if(s[i] == 'W') {
      w[i] = w[i-1] + 1;
      e[i] = e[i-1];
    } else {
      e[i] = e[i-1] + 1;
      w[i] = w[i-1];
    }
  }
  int res = min(numeric_limits<int>::max(), e[n-1] - e[0]);
  for(int i=1;i<n-1;i++) {
    res = min(res, w[i-1] + e[n-1] - e[i]);
  }
  res = min(res, w[n-2]);
  return res;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << solve(n, s);
}
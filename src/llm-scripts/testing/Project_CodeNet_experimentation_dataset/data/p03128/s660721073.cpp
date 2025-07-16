#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void chmax(string &a, string b) {
  if (a == "-") { a = b; }
  else if (a.size() < b.size()) { a = b; }
  else if (a.size() == b.size()) {
    if (a < b) { a = b; }
  }
}

int main(){
  int match[] = {-1,2,5,5,4,5,6,3,7,6};
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) { cin >> a[i]; }

  vector<string> dp(n+10, "-");
  dp[0] = "";
  for (int i = 0; i < n; i++) {
    if (dp[i] == "-") { continue; }
    for (int j = 0; j < m; j++) {
      chmax(dp[i + match[a[j]]], dp[i] + (char)('0'+a[j]));
    }
  }
  cout << dp[n] << endl;
  return 0;
}
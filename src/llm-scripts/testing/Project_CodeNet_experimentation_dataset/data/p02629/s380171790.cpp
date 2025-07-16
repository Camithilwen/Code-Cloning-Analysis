#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

string a26(ll n) {
  string res = "";
  while (n) {
    --n;
    res += (char)('a' + (n % 26));
    n /= 26;
  }
  reverse(res.begin(), res.end());
  return res;
}

ll N;
void input() { cin >> N; }
void solve() { cout << a26(N) << endl; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}
#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int H, W;
  cin >> H >> W;
  map<int, int> S, freq;
  for (int i = 0; i < W; i++) {
    S[i] = i;
    freq[0]++;
  }
  for (int i = 0; i < H; i++) {
    int A, B;
    cin >> A >> B;
    --A; --B;
    int mx = -1;
    while (true) {
      auto it = S.upper_bound(B);
      if (it == S.begin()) break;
      --it;
      if (it->first < A) break;
      mx = max(mx, it->second);
      if (--freq[it->first - it->second] == 0) freq.erase(it->first - it->second);
      S.erase(it);
    }
    if (mx != -1 && B + 1 != W) {
      if (S.count(B + 1)) {
        if (--freq[B + 1 - S[B + 1]] == 0) freq.erase(B + 1 - S[B + 1]);
        S[B + 1] = max(S[B + 1], mx);
      } else S[B + 1] = mx;
      freq[B + 1 - S[B + 1]]++;
    }
    if (freq.empty()) cout << -1 << nl;
    else cout << (i + 1) + freq.begin()->first << nl;
  }
  return 0;
}

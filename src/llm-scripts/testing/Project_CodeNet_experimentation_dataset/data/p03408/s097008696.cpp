#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  string s;
  map<string, int> S;
  for (int i=0; i<N; i++) {
    cin >> s;
    if (S.count(s)) S.at(s) += 1;
    else S[s] = 1;
  }
  
  int M;
  cin >> M;
  for (int i=0; i<M; i++) {
    cin >> s;
    if (S.count(s)) S.at(s) -= 1;
  }
  
  using pis = pair<int, string>;
  priority_queue<pis> cnt;
  for (auto x : S) {  // 要素はキーと値のpair
    cnt.push(pair(x.second, x.first));
  }
  
  if (cnt.top().first < 0) cout << 0 << endl;
  else cout << cnt.top().first << endl;
  
  return 0;
}

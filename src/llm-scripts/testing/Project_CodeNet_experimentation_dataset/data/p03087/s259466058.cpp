#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;

  string S;
  map<int, int> mp;
  int total_acs = 0;
  rep(i,0,N-1) {
    char c;
    cin >> c;
    if (S.back() == 'A' && c == 'C') {
      total_acs++;
    }
    mp[i] = total_acs;
    S.push_back(c);
  }

  vector<int> answers;
  rep(i,0,Q-1) {
    int l, r;
    cin >> l >> r;
    int answer = mp[r-1] - mp[l-1];
    answers.push_back(answer);
  }

  for (int answer: answers)
    cout << answer << endl;

  return 0;
}

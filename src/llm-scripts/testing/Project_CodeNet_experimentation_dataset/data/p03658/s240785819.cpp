#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  rep(i, N) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int sum = 0;
  rep(i, K) {
    sum += vec.at(i);
  }
  cout << sum << endl;
}
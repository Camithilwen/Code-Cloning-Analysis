#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, M;
  cin >> N >> M;
  unordered_map<int64_t, int64_t> count;
  int64_t sum = 0;
  count[sum]++;
  rep(i, N) {
    int a;
    cin >> a;
    sum = (sum + a) % M;
    count[sum]++;
  }

  int64_t answer = 0;
  for (auto& n : count) {
    answer += (n.second) * (n.second - 1) / 2;
  }
  cout << answer << endl;
  return 0;
}
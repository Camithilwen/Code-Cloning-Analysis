#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX_N = 200000;

struct Node {
  int idx;
  int skipCnt;
  int takeCnt;
  ll sum;

  Node(int idx = -1, int skipCnt = -1, int takeCnt = -1, ll sum = -1) {
    this->idx = idx;
    this->skipCnt = skipCnt;
    this->takeCnt = takeCnt;
    this->sum = sum;
  }

  bool operator>(const Node &n) const {
    return idx > n.idx;
  }
};

int main() {
  int N;
  cin >> N;
  ll dp[N][3];
  int takeLimit = N / 2;
  int skipLimit = (N % 2 == 0) ? 1 : 2;

  vector<ll> A;
  ll a;

  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);

    for (int s = 0; s < 3; ++s) {
      dp[i][s] = LLONG_MIN;
    }
  }

  priority_queue <Node, vector<Node>, greater<Node>> pque;
  pque.push(Node(0, 0, 0, 0));
  ll ans = LLONG_MIN;

  while (!pque.empty()) {
    Node node = pque.top();
    pque.pop();

    // fprintf(stderr, "[%d, skipCnt: %d, takeCnt: %d, %lld]\n", node.idx, node.skipCnt, node.takeCnt, node.sum);

    if (node.takeCnt == takeLimit) {
      ans = max(ans, node.sum);
      continue;
    }

    if (node.sum <= dp[node.idx][node.skipCnt]) continue;
    dp[node.idx][node.skipCnt] = max(dp[node.idx][node.skipCnt], node.sum);

    if (node.skipCnt == skipLimit) {
      int nextIdx = node.idx + 2;
      ll sum = node.sum + A[node.idx];

      pque.push(Node(nextIdx, node.skipCnt, node.takeCnt + 1, sum));
    } else {
      // skip taking number
      pque.push(Node(node.idx + 1, node.skipCnt + 1, node.takeCnt, node.sum));

      // no skip
      pque.push(Node(node.idx + 2, node.skipCnt, node.takeCnt + 1, node.sum + A[node.idx]));
    }
  }

  cout << ans << endl;

  return 0;
}

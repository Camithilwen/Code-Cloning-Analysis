#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<ll>> memo(N + 1, vector<ll>(2));
  memo[0][0] = 0;
  memo[0][1] = -INF;
  for (int i = 0; i < N; i++) {
    memo[i + 1][0] = max(memo[i][0] + A[i], memo[i][1] - A[i]);
    memo[i + 1][1] = max(memo[i][0] - A[i], memo[i][1] + A[i]);
  }
  cout << memo[N][0] << endl;
  return 0;
}
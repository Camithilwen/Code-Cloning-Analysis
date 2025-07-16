#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t N, X;
  cin >> N >> X;
  vector<int64_t> A(N);
  rep(i, N) cin >> A[i];

  int64_t answer = 0;
  for(int i = 1; i < N; ++i) {
    if(X < (A[i-1] + A[i])) {
      int64_t diff = (A[i] + A[i-1]) - X;
      A[i] -= min(A[i], diff);
      answer += diff;
    }
  }
  cout << answer << endl;
  return 0;
}
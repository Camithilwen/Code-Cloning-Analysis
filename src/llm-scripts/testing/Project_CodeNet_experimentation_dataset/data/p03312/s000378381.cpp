#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int64_t const INF = 1e18;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int64_t> A(N);
  int64_t S = 0;
  for(int i = 0; i < 3; ++i) std::cin >> A[i];
  for(int i = 3; i < N; ++i) { std::cin >> A[i]; S += A[i]; }
  int64_t P[4] = { A[0], A[1], A[2], S }, ans = INF;
  int j = 1, l = 3;
  for(int k = 2; k < N-1; ++k) {
    while(j < k-1 && std::abs(P[0]-P[1]) > std::abs(P[0]+A[j]-(P[1]-A[j]))) {
      P[0] += A[j];
      P[1] -= A[j];
      ++j;
    }
    while(l < N-1 && std::abs(P[2]-P[3]) > std::abs(P[2]+A[l]-(P[3]-A[l]))) {
      P[2] += A[l];
      P[3] -= A[l];
      ++l;
    }
    ans = std::min(ans, *std::max_element(P, P+4) - *std::min_element(P, P+4));
    P[1] += A[k];
    P[2] -= A[k];
  }
  fin(ans);
  return 0;
}

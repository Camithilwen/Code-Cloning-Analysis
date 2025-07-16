#include <cstdio>
const int MAXN = 2e5+5;
int seen[MAXN]{ };
int M, N;

int main() {
  scanf(" %d%d", &N, &M);
  int lhs = 1;
  int rhs = N;
  for (int i = 0; i < M; ++i) {
    printf("%d %d\n", lhs, rhs);
    ++lhs;
    --rhs;
    while (seen[rhs - lhs] ||
           seen[N - rhs + lhs] ||
           (2*rhs == N + 2*lhs)) --rhs;
    seen[rhs - lhs] = true;
    seen[N - rhs + lhs] = true;
  }
  return 0;
}
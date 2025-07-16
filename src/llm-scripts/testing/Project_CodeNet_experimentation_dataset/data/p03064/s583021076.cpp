#include <stdio.h>
#include <stdlib.h>

#define MAX_N (300L)
#define MAX_A (300L)
#define NUM_MOD (998244353L)

long dp0ss[MAX_N + 1][2 * MAX_N * MAX_A + 1],
    dp1ss[MAX_N + 1][2 * MAX_N * MAX_A + 1];

long mod(long n, long k) { return n % k >= 0 ? n % k : n % k + k; }

int main(int argc, char *argv[]) {
  // read inputs
  long N, as[MAX_N];
  scanf("%ld", &N);
  for (long i = 0; i < N; i++) {
    scanf("%ld", &as[i]);
  }

  // solve dp
  // init
  dp0ss[0][0 + MAX_N * MAX_A] = 1;
  dp1ss[0][0 + MAX_N * MAX_A] = 1;
  // update
  for (long i = 0; i < N; i++) {
    const long a = as[i];
    for (long d = -MAX_N * MAX_A; d <= MAX_N * MAX_A; d++) {
      if (d - a >= -MAX_N * MAX_A) {
        dp0ss[i + 1][d - a + MAX_N * MAX_A] =
            mod(dp0ss[i + 1][d - a + MAX_N * MAX_A] +
                    2 * dp0ss[i][d + MAX_N * MAX_A],
                NUM_MOD);
        dp1ss[i + 1][d - a + MAX_N * MAX_A] = mod(
            dp1ss[i + 1][d - a + MAX_N * MAX_A] + dp1ss[i][d + MAX_N * MAX_A],
            NUM_MOD);
      }
      if (d + a <= MAX_N * MAX_A) {
        dp0ss[i + 1][d + a + MAX_N * MAX_A] = mod(
            dp0ss[i + 1][d + a + MAX_N * MAX_A] + dp0ss[i][d + MAX_N * MAX_A],
            NUM_MOD);
        dp1ss[i + 1][d + a + MAX_N * MAX_A] = mod(
            dp1ss[i + 1][d + a + MAX_N * MAX_A] + dp1ss[i][d + MAX_N * MAX_A],
            NUM_MOD);
      }
    }
  }
  // for (long i = 0; i < N; i++) {
  //   long s = 0;
  //   for (long d = -MAX_N * MAX_A; d <= MAX_N * MAX_A; d++) {
  //     s += dp0ss[i + 1][d + MAX_N * MAX_A];
  //   }
  //   printf("i = %ld, s = %ld\n", i, s);
  // }

  // subtract from 3^N to get answer
  long ans = 1;
  for (long i = 0; i < N; i++) {
    ans = mod(ans * 3, NUM_MOD);
  }
  for (long d = 0; d <= MAX_N * MAX_A; d++) {
    ans = mod(ans - 3 * dp0ss[N][d + MAX_N * MAX_A], NUM_MOD);
  }
  ans = mod(ans + 3 * dp1ss[N][0 + MAX_N * MAX_A], NUM_MOD);
  printf("%ld\n", ans);

  return 0;
}

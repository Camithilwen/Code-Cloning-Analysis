#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (1000L)
#define NUM_MOD (1000000007L)

using namespace std;

long mod_pow(long n, long k, long mod) {
  long res = 1, num = n;
  while (k > 0) {
    if (k % 2 == 1) {
      res = res * num % mod;
    }
    k /= 2;
    num = num * num % mod;
  }
  return res;
}

long fs[MAX_N + 1], finvs[MAX_N + 1], invs[MAX_N + 1];

void fact_init(long N) {
  fs[0] = fs[1] = 1;
  finvs[0] = finvs[1] = 1;
  invs[1] = 1;
  for (int i = 2; i <= N; i++) {
    fs[i] = fs[i - 1] * i % NUM_MOD;
    invs[i] = NUM_MOD - invs[NUM_MOD % i] * (NUM_MOD / i) % NUM_MOD;
    finvs[i] = finvs[i - 1] * invs[i] % NUM_MOD;
  }
}

long num_comb(long i, long j, long k) {
  long res = 1;
  res = res * fs[i] % NUM_MOD;
  res = res * finvs[i - k * j] % NUM_MOD;
  res = res * finvs[k] % NUM_MOD;
  res = res * mod_pow(finvs[j], k, NUM_MOD) % NUM_MOD;
  return res;
}

int main(int argc, char *argv[]) {
  // read inputs
  long N, A, B, C, D;
  scanf("%ld %ld %ld %ld %ld", &N, &A, &B, &C, &D);

  // init
  fact_init(N);

  // solve dp
  long dpss[MAX_N + 1][MAX_N + 1];
  // initialize
  for (long j = 0; j <= N; j++) {
    dpss[0][j] = 1;
  }
  for (long i = 1; i <= N; i++) {
    // B is the maximum number of people per group
    if (i % B == 0 && i / B >= C && i / B <= D) {
      dpss[i][B] = num_comb(i, B, i / B);
    } else {
      dpss[i][B] = 0;
    }
  }
  // update
  for (long i = 1; i <= N; i++) {
    for (long j = B - 1; j >= A; j--) {
      long dp = 0;
      // dp = max(dp, dpss[i][j + 1]);
      dp = (dp + dpss[i][j + 1]) % NUM_MOD;
      for (long k = C, k_last = min(D, i / j); k <= k_last; k++) {
        dp = (dp + dpss[i - k * j][j + 1] * num_comb(i, j, k) % NUM_MOD) % NUM_MOD;
        // printf("i = %ld, j = %ld, k = %ld, dpss[i - k * j] = %ld, num_comb = %ld\n", i, j, k,
        //        dpss[i - k * j][j + 1], num_comb(i, j, k));
      }
      dpss[i][j] = dp;
    }
  }
  // for (long i = 0; i <= N; i++) {
  //   printf("i = %ld:", i);
  //   for (long j = A; j <= B; j++) {
  //     printf(" %ld", dpss[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%ld\n", dpss[N][A]);

  return 0;
}

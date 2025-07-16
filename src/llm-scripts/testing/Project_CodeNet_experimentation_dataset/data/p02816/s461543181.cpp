#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

/* Zalgorithm */

// A[i] := S と S[i:|S|-1] の最長共通接頭辞の長さ

void Zalgorithm(const char *S, int *A) {
  int i = 1, j = 0, k, n = strlen(S);
  A[0] = n;
  while (i < n) {
    while (i + j < n && S[j] == S[i + j]) j++;
    A[i] = j;
    if (j == 0) {
      i++;
      continue;
    }
    for (k = 1; i + k < n && k + A[k] < j; k++) A[i + k] = A[k];
    i += k;
    j -= k;
  }
}


int N, A[SIZE], B[SIZE];
int z[30][SIZE*5];
char S[30][SIZE*5];

int main() {

  scanf("%d", &N);

  for (int i=0; i<N; i++) scanf("%d", A+i);
  for (int i=0; i<N; i++) scanf("%d", B+i);

  for (int i=0; i<N*5; i++) {
    int tmp;
    if (i < N)
      tmp = B[i];
    else if (i < N*3)
      tmp = A[i%N];
    else
      tmp = A[i%N] ^ ((1 << 30) - 1);

    for (int j=0; j<30; j++) {
      S[j][i] = tmp % 2 + 1;
      tmp /= 2;
    }
  }

  for (int i=0; i<30; i++)
    Zalgorithm(S[i], z[i]);

  for (int i=0; i<N; i++) {
    int b = A[i] ^ B[0];
    bool ok = true;

    for (int j=0; j<30; j++) {
      if (b & (1 << j)) {
        ok &= z[j][i+N*3] >= N;
      } else {
        ok &= z[j][i+N] >= N;
      }
    }

    if (ok) {
      printf("%d %d\n", i, b);
    }
  }


  return 0;
}

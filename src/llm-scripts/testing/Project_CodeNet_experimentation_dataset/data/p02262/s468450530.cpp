/*
 * d.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const int MAX_N = 1000000;
const int MAX_M = 20;

/* typedef */

typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

/* global variables */

int as[MAX_N], gs[MAX_M];

/* subroutines */
int insertion_sort(int as[], int n, int g) {
  int cnt = 0;
  for (int i = g; i < n; i++) {
    int v = as[i];
    int j = i - g;
    while (j >= 0 && as[j] > v) {
      as[j + g] = as[j];
      j = j - g;
      cnt++;
    }
    as[j + g] = v;
  }
  return cnt;
}

int shell_sort(int as[], int n, int gs[], int m) {
  int cnt = 0;
  for (int i = 0; i < m; i++)
    cnt += insertion_sort(as, n, gs[i]);
  return cnt;
}

/* main */

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> as[i];

  int g;
  for (g = 1; g <= n; g <<= 1);

  int m = 0;
  for (g >>= 1; g > 0; g >>= 1, m++) gs[m] = g;

  int cnt = shell_sort(as, n, gs, m);

  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    if (i) putchar(' ');
    printf("%d", gs[i]);
  }
  putchar('\n');
  printf("%d\n", cnt);

  for (int i = 0; i < n; i++) printf("%d\n", as[i]);
  
  return 0;
}
// Author: 23forever
#include <bits/stdc++.h>
//#define debug
const int MAXN = 40;
const int N = 5 + 7 + 5;
const int P = 1e9 + 7;
using namespace std;

inline void read(int &x) {
  x = 0; char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
}

int n, x, y, z;
int dp[MAXN + 5][1 << N];
int banned, S;

void print(int x) {
  bitset < 20 > tmp(x);
  cout << tmp << endl;
}

void init() {
  read(n), read(x), read(y), read(z);
  //cout << (1 << 5 - 1) << endl;
  banned = (1 << x + y + z - 1) | (1 << y + z - 1) | (1 << z - 1); 
  S = (1 << x + y + z) - 1;
  //print(S);
}

int main() {
#ifdef forever23
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
#endif
  init();

  int ans = 1; dp[0][0] = 1; 
  for (int i = 1; i <= n; ++i) {
    for (int s = 0; s <= S; ++s) {
      for (int j = 1; j <= 10; ++j) {
        int nxt_state = ((1 << j - 1) | (s << j)) & S;
        /*print(s); printf("%d\n", j);
        print(nxt_state);
        puts("");*/   
        if ((nxt_state & banned) != banned) {
          dp[i][nxt_state] = (dp[i][nxt_state] + dp[i - 1][s]) % P;
        }
      }
    }
    ans = 1LL * ans * 10 % P;
  }
  
  for (int s = 0; s <= S; ++s) {
    ans = (ans - dp[n][s] + P) % P;
  }
  printf("%d\n", ans);  
  return 0;
}

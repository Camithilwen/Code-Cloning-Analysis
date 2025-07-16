#include <bits/stdc++.h>
#define N 100020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
int a[3][N], f[N];
bool rev[2];

int main(int argc, char const *argv[]) {
  int n = read();
  for (int i = 1; i <= n; ++ i) {
    a[0][i] = read();
  }
  for (int i = 1; i <= n; ++ i) {
    a[1][i] = read();
  }
  for (int i = 1; i <= n; ++ i) {
    a[2][i] = read();
  }

  for (int i = 1; i <= n; ++ i) {
    if (a[1][i] % 3 != 2 || abs(a[0][i] - a[1][i]) > 1
        || abs(a[2][i] - a[1][i]) > 1) {
      return puts("No"), 0;
    }
    f[i] = a[1][i] / 3 + 1;

    if ((f[i] & 1) != (i & 1)) {
      return puts("No"), 0;
    }

    if (a[0][i] > a[1][i]) {
      rev[f[i] & 1] ^= 1;
    }
  }

  for (int i = 1; i <= n; ++ i) {
    while (f[i] != i) {
      rev[i&1^1] ^= 1;
      swap(f[i], f[f[i]]);
    }
  }

  if (rev[0] || rev[1]) {
    puts("No");
  } else {
    puts("Yes");
  }

  return 0;
}
/*

将每一列变成 x/3+1，如果是倒序则加个负号。

一次操作可以看做：

1 2 3 4 5 -> -3 -2 -1 4 5

let's do some buffs

[ 1  2  3] 4  5
 -3 -2[-1  4  5]
[-3 -2 -5]-4  1
  5  2[ 3 -4  1]
[ 5  2 -1] 4 -3
  1 -2[-5  4 -3]
  1 -2  3 -4  5


*/
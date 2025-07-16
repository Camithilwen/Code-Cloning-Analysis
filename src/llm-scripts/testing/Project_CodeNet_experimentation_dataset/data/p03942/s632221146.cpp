#include <bits/stdc++.h>
#define N 1000020
#define ll long long
using namespace std;
inline int read(){
  int x=0,f=1;char ch=getchar();
  while(ch>'9'||ch<'0')ch=='-'&&(f=0)||(ch=getchar());
  while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
  return f?x:-x;
}
char s[N], t[N];
queue<int> q;

int main(int argc, char const *argv[]) {
  int n = read();
  scanf("%s", s + 1);
  scanf("%s", t + 1);

  if (!strcmp(s + 1, t + 1)) {
    return puts("0"), 0;
  }

  int ans = 0;

  for (int i = n, j = n; i; -- i) {
    if (t[i] == t[i - 1]) continue;
    j = min(j, i);
    while (j && s[j] != t[i]) {
      -- j;
    }
    if (!j) {
      return puts("-1"), 0;
    }

    while (!q.empty() && q.front() >= i + q.size()) {
      q.pop();
    }

    q.push(j);

    if (i != j) {
      ans = max(ans, (int) q.size());
    }
  }

  printf("%d\n", ans + 1);

  return 0;
}
/*
7
atcoder
aaaccce
*/
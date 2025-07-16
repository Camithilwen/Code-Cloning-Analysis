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
int a[N];
vector<int> sig;
int main(int argc, char const *argv[]) {
  int n = read(), m = read();
  for (int i = 1; i <= m; ++ i) {
    a[i] = read();
    if (a[i] & 1) {
      sig.push_back(i);
    }
  }
  size_t sigsize = sig.size();
  if (sigsize > 2) {
    return puts("Impossible"), 0;
  }
  if (sigsize > 0) {
    swap(a[1], a[sig[0]]);
  }
  if (sigsize > 1) {
    swap(a[m], a[sig[1]]);
  }

  if (m == 1) {
    if (a[1] == 1) {
      puts("1\n1\n1");
    } else {
      printf("%d\n2\n%d 1\n", a[1], a[1] - 1);
    }
    return 0;
  }
  
  for (int i = 1; i <= m; ++ i) {
    printf("%d ", a[i]);
  }
  puts("");

  printf("%d\n", a[m] == 1 ? m - 1 : m);
  printf("%d", a[1] + 1);
  for (int i = 2; i < m; ++ i) {
    printf(" %d", a[i]);
  }
  if (a[m] != 1) {
    printf(" %d\n", a[m] - 1);
  } else {
    puts("");
  }
  return 0;
}
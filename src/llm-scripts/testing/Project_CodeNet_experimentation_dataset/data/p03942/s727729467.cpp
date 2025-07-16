#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
using namespace std;
const int maxn = 1000000 + 10;
 
int n, ans = 0;
char a[maxn], b[maxn];
deque <int> q;
 
int main() {
  scanf("%d", &n);
  scanf("%s%s", a + 1, b + 1);
  q.push_back(n + 1);
  for(int i = n, j = n + 1, del = 0;i >= 1;i --) {
    int tmp = j;
    while(j && (j > i || a[j] != b[i])) j --;
    if(!j) {
      puts("-1");
      return 0;
    }
    if(tmp == j) {
      while(!q.empty() && q.back() - del >= i) q.pop_back();
      q.push_back(i + del);
    }
    else {
      del ++;
      if(i != j) {
        ans = max(ans,(int)q.size());
        q.push_front(j + del);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
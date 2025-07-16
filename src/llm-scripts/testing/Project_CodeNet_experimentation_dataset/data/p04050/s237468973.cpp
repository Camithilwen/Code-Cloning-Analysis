#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 100 + 10;

int n, m, a[maxn];
int main() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for(int i = 1;i <= m;i ++) scanf("%d", &a[i]), cnt = cnt + ((a[i] & 1) ? (1) : (0));
	if(cnt > 2) puts("Impossible");
	else {
	  for(int i = 1;i <= m;i ++) {
	    if(a[i] & 1) {
	      if(a[1] & 1) swap(a[i],a[m]);
	      else swap(a[1],a[i]);
			}
		}
		for(int i = 1;i <= m;i ++) printf("%d ", a[i]);
		puts("");
		if(m == 1) a[++ m] = a[1], a[1] = 0;
		a[1] ++;
		a[m] --;
		if(!a[m]) m --;
		printf("%d\n", m);
		for(int i = 1;i <= m;i ++) printf("%d ", a[i]);
		puts("");
	}
  return 0;
}
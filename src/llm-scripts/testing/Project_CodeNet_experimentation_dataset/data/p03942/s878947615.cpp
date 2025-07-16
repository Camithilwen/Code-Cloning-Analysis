#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 1000005;
char S[MAXN], T[MAXN];
int n, q[MAXN], head = 1, tail;
signed main () {
	scanf("%d%s%s", &n, S+1, T+1);
	if(strcmp(S+1, T+1) == 0) { puts("0"); return 0; }
	int ans = 0;
	for(int i = n, j = n; i >= 1; --i) {
		if(T[i] == T[i-1]) continue;
		j = min(j, i);
		for(; j && S[j] != T[i]; --j);
		if(!j) { puts("-1"); return 0; }
		while(head <= tail && q[head] - (tail-head+1) + 1 > i) ++head;
		q[++tail] = j;
		if(i != j) ans = max(ans, tail-head+1);
	}
	printf("%d\n", ans+1);
}
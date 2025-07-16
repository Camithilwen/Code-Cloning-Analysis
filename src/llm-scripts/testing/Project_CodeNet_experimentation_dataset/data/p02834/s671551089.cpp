#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll; 
typedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 2e6 + 5;
struct ed{
	int to, nxt;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}

int n, s, t, dep[N], mx[N], fa[N], ans, tp;
void dfs(int x, int last){
	fa[x] = last;
	dep[x] = dep[last] + 1;
	mx[x] = dep[x];
	for (int i = head[x]; i; i = e[i].nxt){
		int v = e[i].to;
		if (v == last)	continue;
		dfs(v, x);
		mx[x] = max(mx[x], mx[v]);
	}
}
int  main()
{
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 0; i < n - 1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(t, 0);
	t = 1;
	ans = (dep[s] - dep[t]) >> 1;
	while (true){
		if (dep[s] <= t)	break;
		if ((dep[s] - dep[t]) & 1)
			ans = max(ans, mx[s] - t - 1 + tp);
		else
			ans = max(ans, mx[s] - t - 1 + tp);
		s = fa[s];
		t++;
		tp++;
	}
	printf("%d\n", ans);
}
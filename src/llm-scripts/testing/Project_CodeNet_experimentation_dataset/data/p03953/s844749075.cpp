#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 100003;
int n, m, c[N], d[N], cnt;
LL ans[N], x[N], k;
bool vis[N];
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++) scanf("%lld", x + i), c[i] = i;
	for(Rint i = n;i;i --) x[i] -= x[i - 1];
	scanf("%d%lld", &m, &k);
	for(Rint i = 1;i <= m;i ++){
		int v; scanf("%d", &v); swap(c[v], c[v + 1]);
	}
	for(Rint i = 1;i <= n;i ++) if(!vis[i]){
		cnt = 0;
		for(Rint j = i;!vis[j];j = c[j]) vis[d[cnt ++] = j] = true;
		for(Rint j = 0;j < cnt;j ++)
			ans[d[j]] = x[d[(j + k) % cnt]];
	}
	for(Rint i = 1;i <= n;i ++){
		ans[i] += ans[i - 1];
		printf("%lld.0\n", ans[i]);
	}
}
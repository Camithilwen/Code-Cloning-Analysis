#include<cstdio>
#include<algorithm>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 200003;
int n;
LL ans, d, a[N], f[N], g[N];
int main(){
	scanf("%d%lld", &n, &d);
	for(Rint i = 1;i <= n;i ++){
		scanf("%lld", a + i);
		ans += a[i];
	}
	f[1] = a[1];
	for(Rint i = 2;i <= n;i ++) f[i] = min(f[i - 1] + d, a[i]);
	g[n] = a[n];
	for(Rint i = n - 1;i;i --) g[i] = min(g[i + 1] + d, a[i]);
	for(Rint i = 2;i < n;i ++) ans += min(f[i], g[i]);
	printf("%lld\n", ans + (n - 1) * d);
}
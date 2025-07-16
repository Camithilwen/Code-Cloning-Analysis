#include <iostream>
#include<map>
using namespace std;
const int maxn = 2e6 + 10;
typedef pair<int, int> P;
int fa[maxn], ma[maxn];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		fa[i] = i;
		ma[i] = i;
	}
}
int find(int* fa, int x)//找到根节点
{
	if (fa[x] == x)
	{	
		return fa[x];
	}
	return fa[x] = find(fa, fa[x]);
}
void unin(int a, int b, int* fa)
{
	a = find(fa, a);//找到a根节点
	b = find(fa, b);//找到b跟节点
	fa[a] = b;//a为b的父节点
}
map<P, int>ans;
int main()
{
	int n, k, l;
	while (scanf("%d%d%d", &n, &k, &l) != EOF)
	{
		init(n);
		ans.clear();
		for (int i = 0; i < k; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unin(a, b, ma);
		}
		for (int i = 0; i < l; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			{
				unin(a, b, fa);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			ans[make_pair(find(ma, i), find(fa, i))]++;
		}
		for (int i = 1; i <= n; ++i)
		{
			i == n ? printf("%d\n", ans[make_pair(find(ma, i), find(fa, i))]) : printf("%d ", ans[make_pair(find(ma, i), find(fa, i))]);
		}
	}
	return 0;
}
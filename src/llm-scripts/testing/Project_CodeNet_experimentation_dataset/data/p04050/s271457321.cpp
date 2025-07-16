#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int sum, n;
int a[101], odd, evn, pos[101];
int b[101], cnt;

void work()
{
	if(n == 1)
	{
		if(a[1] == 1) b[++cnt] = 1;
		else b[++cnt] = 1, b[++cnt] = a[1] - 1;
		return;
	}
	if(a[1] & 1) b[++cnt] = a[1] + 1;
	else b[++cnt] = 1, b[++cnt] = a[1];
	for(int i=2; i<n; i++) b[++cnt] = a[i];
	if(a[n]==1) return;
	else b[++cnt] = a[n]-1;
}

int main()
{
	scanf("%d%d", &sum, &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
		if(a[i] & 1) pos[++odd] = i;
		else evn++;
	if(odd > 2) printf("Impossible\n"), exit(0);
	if(odd == 0) work();
	else if(odd == 1) swap(a[pos[1]], a[1]), work();
	else swap(a[pos[1]], a[1]), swap(a[pos[2]], a[n]), work();
	for(int i=1; i<=n; i++) printf("%d ", a[i]); putchar('\n');
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; i++) printf("%d ", b[i]); putchar('\n');
	return 0;
}
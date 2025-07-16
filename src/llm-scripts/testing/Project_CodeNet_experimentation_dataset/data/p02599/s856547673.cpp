#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, siz, num;
int w[N], cnt[N], belong[N];
int now, ans[N];

struct query{
	int l, r, id;
}q[N];

//bool cmp(query a, query b)
//{
//	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
//}
bool cmp(query a, query b) {
    return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}

void add(int pos)
{
	if(!cnt[w[pos]]) ++now;
	++cnt[w[pos]];
}

void del(int pos)
{
	--cnt[w[pos]];
	if(!cnt[w[pos]]) --now;
}

int main()
{
	scanf("%d%d", &n, &m);
	siz = sqrt(n);
	num = ceil((double) n / siz);
//	cout << num << endl;
	for (int i = 1; i <= num; i ++)
	{
		for (int j = (i - 1) * siz + 1; j <= i * siz; j ++)
		{
			belong[j] = i;
		}
	}
	for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i ++)
	{
		q[i].id = i;
		scanf("%d%d", &q[i].l, &q[i].r);
	}
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i ++)
	{
		int ql = q[i].l, qr = q[i].r;
		while(l < ql) del(l ++);
		while(l > ql) add(-- l);
		while(r < qr) add(++ r);
		while(r > qr) del(r --);
		ans[q[i].id] = now;
	}
	for (int i = 1; i <= m; i ++)
		printf("%d\n", ans[i]);
}
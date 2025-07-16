#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int last[N], root[N];
struct seg{
	int l, r;
	int val;
}tr[N * 30];
int tot;

void build(int &rt, int l, int r)
{
	rt = ++tot;
	tr[rt].val = 0; 
	if(l == r) return ;
	int mid =l + r >> 1;
	build(tr[rt].l, l, mid), build(tr[rt].r, mid + 1, r);
}

void update(int &p, int q, int x, int c, int l, int r)
{
	p = ++ tot;
	tr[p] = tr[q];
	tr[p].val += c;
	if(l == r) return ;
	int mid = l + r >> 1;
	if(x <= mid) update(tr[p].l, tr[q].l, x,c, l, mid);
	else update(tr[p].r, tr[q].r, x, c,mid + 1, r);
}

int query(int p, int q, int L, int R, int l, int r)
{
	if(L <= l && R >= r)
	return tr[q].val - tr[p].val;
	int mid = l + r >> 1;
	int res = 0;
	if(L <= mid) res += query(tr[p].l, tr[q].l, L, R, l, mid);
	if(R >  mid) res += query(tr[p].r, tr[q].r, L, R, mid + 1, r);
	return res;
}

int main()
{
	int n, m;
	n = read(); m = read();
	build(root[0], 0, n);
	for (int i = 1; i <= n; i ++)
	{
		int x;
		x = read();
		update(root[i], root[i - 1], last[x], 1, 0, n);
		last[x] = i;	
	}
	while(m --)
	{
		int x, y;
		x = read(), y = read();
		printf("%d\n", query(root[x - 1], root[y], 0, x - 1, 0, n));
	}
}
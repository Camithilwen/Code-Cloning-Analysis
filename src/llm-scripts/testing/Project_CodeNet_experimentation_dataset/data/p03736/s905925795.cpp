#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iostream>
#include <cstring>
#include <algorithm>
#define R register
#define IN inline
#define W while
#define ls (now << 1)
#define rs ((now << 1) | 1)
#define MX 200500
#define gc getchar()
#define ll long long
template <class T>
IN void in(T &x)
{
	x = 0; R char c = gc;
	for (; !isdigit(c); c = gc);
	for (;  isdigit(c); c = gc)
	x = (x << 1) + (x << 3) + c - 48;
}
template <class T> IN T max(T a, T b) {return a > b ? a : b;}
template <class T> IN T min(T a, T b) {return a < b ? a : b;}
template <class T> IN T abs(T a) {return a > 0 ? a : -a;}
int n, q;
struct Node
{
	ll val[3], tag;
	Node(){std::memset(val, 63, sizeof(val));}
}tree[MX << 2];
IN void pushup(R int now)
{
	tree[now].val[0] = min(tree[ls].val[0], tree[rs].val[0]);
	tree[now].val[1] = min(tree[ls].val[1], tree[rs].val[1]);
	tree[now].val[2] = min(tree[ls].val[2], tree[rs].val[2]);
}
IN void pushdown(R int now)
{
	if (tree[now].tag)
	{
		tree[ls].val[0] += tree[now].tag;
		tree[ls].val[1] += tree[now].tag;
		tree[ls].val[2] += tree[now].tag;
		tree[ls].tag	+= tree[now].tag;
		tree[rs].val[0] += tree[now].tag;
		tree[rs].val[1] += tree[now].tag;
		tree[rs].val[2] += tree[now].tag;
		tree[rs].tag	+= tree[now].tag;
		tree[now].tag = 0;
	}
}
void modify(R int now, R int lef, R int rig, R int pos, R ll v)
{
	if (lef == rig)
	{
		tree[now].val[0] = v;
		tree[now].val[1] = v - pos;
		tree[now].val[2] = v + pos;
		return;
	}
	pushdown(now);
	int mid = lef + rig >> 1;
	if (pos <= mid) modify(ls, lef, mid, pos, v);
	else modify(rs, mid + 1, rig, pos, v);
	pushup(now);
}
IN void add(R ll v)
{
	tree[1].tag += v;
	tree[1].val[0] += v;
	tree[1].val[1] += v;
	tree[1].val[2] += v;
}
ll query(R int now, R int lef, R int rig, R int lb, R int rb, R int id)
{
	if (lef >= lb && rig <= rb) return tree[now].val[id];
	pushdown(now);
	int mid = lef + rig >> 1; ll ret = LONG_LONG_MAX;
	if (lb <= mid) ret = query(ls, lef, mid, lb, rb, id);
	if (rb > mid) ret = min(ret, query(rs, mid + 1, rig, lb, rb, id));
	return ret;
}
int main(void)
{
	int a, b, last, cur, del;
	ll res1, res2, res3;
	in(n), in(q), in(a), in(b);
	in(last);
	modify(1, 1, n, b, abs(last - a));
	modify(1, 1, n, a, abs(last - b));
	W (--q)
	{
		in(cur); del = abs(last - cur);
		res1 = query(1, 1, n, cur, cur, 0) + del;
		res2 = query(1, 1, n, 1, cur, 1) + cur;
		res3 = query(1, 1, n, cur + 1, n, 2) - cur;
		res1 = min(res1, min(res2, res3));
		add(del);
		modify(1, 1, n, last, res1);
		last = cur;
	}
	printf("%lld", tree[1].val[0]);
}
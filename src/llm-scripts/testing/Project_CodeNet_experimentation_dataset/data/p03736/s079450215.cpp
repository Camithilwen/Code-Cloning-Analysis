// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename _tp> inline void read(_tp&x){
	char ch=getchar(),ob=0;x=0;
	while(ch!='-'&&!isdigit(ch))ch=getchar();if(ch=='-')ob=1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(ob)x=-x;
}

#define lson l,mid,x<<1
#define rson mid+1,r,x<<1|1

const ll INF = 1e18;
const int N = 601000;
ll mi0[N], mi1[N], sg[N], tag[N];
int n, Q;

void build(int l, int r, int x) {
	sg[x] = mi0[x] = mi1[x] = INF;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(lson), build(rson);
}

inline void down(int x) {
	const int l = x << 1, r = l | 1;
	ll&v = tag[x];
	sg[l] += v, sg[r] += v,
	mi0[l] += v, mi1[l] += v,
	mi0[r] += v, mi1[r] += v,
	tag[l] += v, tag[r] += v;
	v = 0;
}

void upd(int l, int r, int x, int ps, ll vl) {
	if(l == r) {
		if(sg[x] > vl) {
			sg[x] = vl;
			mi0[x] = vl - l;
			mi1[x] = vl + l;
		}
		return ;
	}
	if(tag[x]) down(x);
	int mid = l + r >> 1;
	if(ps <= mid) upd(lson, ps, vl);
	else upd(rson, ps, vl);
	mi0[x] = min(mi0[x<<1], mi0[x<<1|1]);
	mi1[x] = min(mi1[x<<1], mi1[x<<1|1]);
}

ll get0(int l, int r, int x, int R) {
	if(r <= R) return mi0[x];
	if(tag[x]) down(x);
	int mid = l + r >> 1;
	if(R <= mid) return get0(lson, R);
	return min(get0(lson, R), get0(rson, R));
}

ll get1(int l, int r, int x, int L) {
	if(L <= l) return mi1[x];
	if(tag[x]) down(x);
	int mid = l + r >> 1;
	if(mid < L) return get1(rson, L);
	return min(get1(lson, L), get1(rson, L));
}

ll get(int l, int r, int x) {
	if(l == r) return sg[x];
	if(tag[x]) down(x);
	int mid = l + r >> 1;
	return min(get(lson), get(rson));
}

int main() {
	read(n), read(Q);
	build(1, n, 1);
	int x, y, z;
	read(x), read(y), read(z);
	upd(1, n, 1, x, abs(y - z));
	upd(1, n, 1, y, abs(x - z));
	while(--Q) {
		read(x), y = abs(x - z);
		ll vl = min(get0(1, n, 1, x) + x, get1(1, n, 1, x) - x);
		mi0[1] += y, mi1[1] += y, tag[1] += y;
		upd(1, n, 1, z, vl), z = x;
	}
	printf("%lld\n", get(1, n, 1));
	return 0;
}
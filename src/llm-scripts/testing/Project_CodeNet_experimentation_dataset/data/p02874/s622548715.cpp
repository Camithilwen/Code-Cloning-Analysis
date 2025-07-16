#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

struct st{
	int l, r;
} a[N];

int n, mx, fl[N], fr[N], bl[N], br[N];

bool cmp(st p, st q) {
	if (p.r != q.r) return p.r < q.r;
	else return p.l < q.l;
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i].l, &a[i].r);
	}
	sort(a, a + n, cmp);
	fl[0] = a[0].l; fr[0] = a[0].r;
	for (i = 1; i < n; i++) {
		fl[i] = max(fl[i - 1], a[i].l);
		fr[i] = min(fr[i - 1], a[i].r);
	}
	bl[n - 1] = a[n - 1].l; br[n - 1] = a[n - 1].r;
	for (i = n - 2; i >= 0; i--) {
		bl[i] = max(bl[i + 1], a[i].l);
		br[i] = min(br[i + 1], a[i].r);
	}
	for (i = 0; i < n; i++) {
		mx = max(mx, a[i].r - a[i].l + 1 + max(0, fr[n - 1] - fl[n - 1] + 1));
	}
	for (i = 0; i < n - 1; i++) {
		mx = max(mx, max(0, fr[i] - fl[i] + 1) + max(0, br[i + 1] - bl[i + 1] + 1));
	}
    cout << mx << endl;
    return 0;
}
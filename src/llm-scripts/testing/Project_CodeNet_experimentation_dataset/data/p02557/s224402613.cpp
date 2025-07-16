#include <bits/stdc++.h>
#define F(i, x, y) for (int i = (x); i <= (y); ++i)
#define Fr(i, x, y) for (int i = (x); i < (y); ++i)
using namespace std;
typedef long long ll;

const int N = 300000 + 5;
int n, A[N], cnt[N], B[N], Fl[N], Fr[N];

int tg[N];
void ad(int x, int t) {
	if (x < 0 || x >= n) return ;
	tg[x] += t;
}
void add(int l, int r) {
	if (l>r) return ;
//	cerr << "add: " << l << " " << r << '\n';
	ad(l, 1); ad(r+1, -1);
}
int main() {
	memset (Fl, -1, sizeof(Fl));
	memset (Fr, -1, sizeof(Fr));
	scanf ("%d", &n);
	Fr(i, 0, n) scanf ("%d", &A[i]), ++cnt[A[i]], Fr[A[i]] = i;
	for (int i = n-1; i >= 0; --i) Fl[A[i]] = i;
	Fr(i, 0, n) scanf ("%d", &B[i]), ++cnt[B[i]];
	if (*max_element(cnt, cnt + 300000) > n) return puts("No"), 0;
	Fr(i, 0, n) {
		// intersect: Fr = i initially Fr = Fr, i = 1
		// Fl = j, initially Fl = Fl, i = 1
		if (Fl[B[i]] == -1) continue;
		int stl = (i - Fr[B[i]] + n) % n, str = (i - Fl[B[i]] + n) % n;
		if (stl > str)	add(stl, n-1), add(0, str);
		else add(stl, str);
	}
	for (int i = 0; i < n; ++i) {
		if (i) tg[i] += tg[i - 1]; 
		if (!tg[i]){
			puts("Yes");
			int cur = i;
			for (int j = 1; j <= n; ++j) {
				printf("%d ", B[cur]);
				(cur += 1) %= n;
			}
			return 0; 
		}
	}
	puts("No");
	return 0;
}

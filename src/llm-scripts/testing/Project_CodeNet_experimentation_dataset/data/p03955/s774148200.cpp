#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 1e5 + 5 ;
using namespace std ;
int cnt, n, a[4][N], d[5], b[N], bit[N], c[N], ind[N], outd[N] ; bool vis[N] ;
struct poi {
	int l, r ;
} p[N] ;
set <int> S ;
void put(int x) { for ( ; x <= n ; x += x & (- x)) ++ bit[x] ; }
int get(int x) { int res = 0 ; for ( ; x ; x -= x & (- x)) res += bit[x] ; return res ; }
bool cmp(poi a, poi b) {
	return a.r < b.r ;
}
int main() {
	scanf("%d", &n) ;
	rep(i, 1, 3) rep(j, 1, n) scanf("%d", &a[i][j]) ;
	rep(j, 1, n) {
		rep(i, 1, 3) d[i] = a[i][j] ;
		sort(d + 1, d + 4) ;
		if (d[1] % 3 != 1 || d[2] != d[1] + 1 || d[3] != d[2] + 1 || d[2] != a[2][j] || vis[d[1] / 3]) {
			printf("No\n") ;
			return 0 ; 
		}
		vis[d[1] / 3] = true ;
		b[d[1] / 3 + 1] = j, c[j] = d[1] / 3 + 1 ;
		if ((c[j] - j) % 2) {
			printf("No\n") ;
			return 0 ;
		}
	}
/*	rep(i, 1, n) bit[i] = 0 ;
	for (int i = n; i; -- i) {
		if (i & 1) {
			put(c[i]) ;
			continue ;
		}
		if (((get(i) + abs(b[i] - i) / 2) & 1) ^ (a[1][b[i]] > a[3][b[i]])) {
			printf("No\n") ;
			return 0 ;
		}
	}
	rep(i, 1, n) bit[i] = 0 ;
	for (int i = n; i; -- i) {
		cout << i << endl ;
		if (i & 1) {
			if (((get(i) + abs(b[i] - i) / 2) & 1) ^ (a[1][b[i]] > a[3][b[i]])) {
				printf("No\n") ;
				return 0 ;
			}
		} else put(c[i]) ;
	}
*/
	rep(i, 1, n) {
		if (c[i] < i) ++ outd[i - 1], -- outd[c[i] - 1] ; else
		  ++ ind[i + 1], -- ind[c[i] + 1] ;
	}
	rep(i, 1, n) ind[i] += ind[i - 2] ;
	for (int i = n; i; -- i) outd[i] += outd[i + 2] ;
	rep(i, 1, n) if (ind[i] != outd[i]) {
		printf("No\n") ;
		return 0 ;
	}
	cnt = 0 ; 
	rep(i, 1, n) if (i & 1) {
/*		if (ind[i] & 1) ++ cnt ;
//		if (ind[i] & 1) S.insert(i) ;
		if (((abs(c[i] - i) / 2) & 1) ^ (a[3][i] < a[1][i])) ; else continue ;
		++ cnt ; */
		cnt += a[3][i] < a[1][i] ;
//		p[cnt].l = min(c[i], i), p[cnt].r = max(c[i], i) ;
	} else {
		cnt += get(n - c[i] + 1) & 1 ;
		put(n - c[i] + 1) ;
	}
	if (cnt & 1) {
		printf("No\n") ;
		return 0 ; 
	}
	rep(i, 1, n) bit[i] = 0 ;
//	sort(p + 1, p + cnt + 1, cmp) ;
//	rep(i, 1, n) cout << c[i] << " " ; cout << endl ;
/*	rep(i, 1, cnt) {
		std :: set <int> :: iterator it = S.lower_bound(p[i].l) ;
		if (it == S.end() || (*it) > p[i].r) {
			S.insert(p[i].r) ;
		} else {
			S.erase(it) ;
		}
	}
	if (!S.empty()) {
		printf("No\n") ;
		return 0 ; 
	}*/
/*	if (cnt & 1) {
		printf("No\n") ;
		return 0 ;
	}
	cnt = 0 ;
*/	
	cnt = 0 ;
	rep(i, 1, n) if (i & 1) cnt += get(n - c[i] + 1) & 1, put(n - c[i] + 1) ; else {
/*		if (ind[i] & 1) ++ cnt ;
//		if (ind[i] & 1) S.insert(i) ;
		if (((abs(c[i] - i) / 2) & 1) ^ (a[3][i] < a[1][i])) ; else continue ;
		++ cnt ;
*///		p[cnt].l = min(c[i], i), p[cnt].r = max(c[i], i) ;
		cnt += a[3][i] < a[1][i] ;
	}  
	if (cnt & 1) {
		printf("No\n") ;
		return 0 ; 
	}
//	sort(p + 1, p + cnt + 1, cmp) ;
//	rep(i, 1, cnt) cout << p[i].l << " " << p[i].r << endl ;
//	rep(i, 1, n) if (i & 1) ; else printf("%d ", ind[i]) ; cout << endl ;
/*	rep(i, 1, cnt) {
		std :: set <int> :: iterator it = S.lower_bound(p[i].l) ;
		if (it == S.end() || (*it) > p[i].r) {
			S.insert(p[i].r) ;
		} else {
			S.erase(it) ;
		}
	}
	if (!S.empty()) {
		printf("No\n") ;
		return 0 ;
	}
*/
	
	printf("Yes\n") ;
	return 0 ; 
}
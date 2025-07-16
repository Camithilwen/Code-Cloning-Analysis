/*  */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti				set<int>
#define stpii			set<pair<int, int> >
#define mpii			map<int,int>
#define vi				vector<int>
#define pii				pair<int,int>
#define vpii			vector<pair<int,int> >
#define rep(i, a, n) 	for (int i=a;i<n;++i)
#define per(i, a, n) 	for (int i=n-1;i>=a;--i)
#define clr				clear
#define pb 				push_back
#define mp 				make_pair
#define fir				first
#define sec				second
#define all(x) 			(x).begin(),(x).end()
#define SZ(x) 			((int)(x).size())
#define lson			l, mid, rt<<1
#define rson			mid+1, r, rt<<1|1
#define getBits(x)		__builtin_popcount(x)
#define getBitIdx(x)	__builtin_ffs(x)

typedef long long LL;
const int maxn = 45;
int s[maxn][maxn];
int dir[4][2] = {
	-1,0, 1,0, 0,-1, 0,1
};
int n, m;
int stx, sty, edx, edy;
int ansd;

inline bool judge(int x, int y) {
	return x<0 || x>=n || y<0 || y>=m;
}

void init() {
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == 2) {
				stx = i;
				sty = j;
				s[i][j] = 0;
			} else if (s[i][j] == 3) {
				edx = i;
				edy = j;
				s[i][j] = 0;
			}
		}
	}
}

void dfs(int dep, int x, int y) {
	if (dep >= ansd) return;
	if (x==edx && y==edy) {
		ansd = dep;
		return ;
	}
	
	int xx, yy;
	int flag;
	
	rep(i, 0, 4) {
		xx = x;
		yy = y;
		if (judge(xx+dir[i][0], yy+dir[i][1]) || s[xx+dir[i][0]][yy+dir[i][1]] == 1) continue;
		
		flag = 1;
		while (true) {
			if (judge(xx+dir[i][0], yy+dir[i][1])) {
				flag = 0;
				break;
			}
			
			if (s[xx+dir[i][0]][yy+dir[i][1]] == 1) {
				flag = -1;
				break;
			}
			
			xx += dir[i][0];
			yy += dir[i][1];
			
			if (xx==edx && yy==edy) {
				break;
			}
		}
		
		if (flag == 0) continue;
		
		if (flag == -1) {
			s[xx+dir[i][0]][yy+dir[i][1]] = 0;
		}
		
		dfs(dep+1, xx, yy);
		
		if (flag == -1) {
			s[xx+dir[i][0]][yy+dir[i][1]] = 1;
		}
	}
}

void solve() {
	init();
	ansd = 11;
	dfs(0, stx, sty);
	if (ansd == 11) ansd = -1;
	printf("%d\n", ansd);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	// #ifndef ONLINE_JUDGE
		// freopen("data.in", "r", stdin);
		// freopen("data.out", "w", stdout);
	// #endif
	
	while (scanf("%d %d", &m,&n)!=EOF && (n||m)) {
		rep(i, 0, n)
			rep(j, 0, m)
				scanf("%d", &s[i][j]);
		solve();
	}
	
	// #ifndef ONLINE_JUDGE
		// printf("time = %ldms.\n", clock());
	// #endif
	
	return 0;
}
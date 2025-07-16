#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void strcpy(auto & S, string * p, int sz, int offset_r, int offset_c, int offset_val) {
	for(int k = 0; k < sz; k++) for(int l = 0; l < sz; l++) if(p[k][l] != '.')
		S[offset_r+k][offset_c+l] = p[k][l] + offset_val * 4;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	if(N == 2) {
		cout << "-1\n";
		return 0;
	}
	string p3[] = {
		"aab",
		"d.b",
		"dcc"
	};
	string p4[] = {
		"aacd",
		"bbcd",
		"cdaa",
		"cdbb"
	};
	string p5[] = {
		"aabba",
		"b.cca",
		"bd..b",
		"ad..b",
		"abbaa",
	};
	string p7[] = {
		"....aba",
		"....aba",
		"....bab",
		"....bab",
		"aabb.cc",
		"bbaad..",
		"aabbd..",
	};
	vector<string> S(N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) S[i] += '.';
	int r = 1;
	while(N%2 == 0 && N >= 6) N /= 2, r *= 2;
	for(int rr = 0; rr < r; rr++) for(int rc = 0; rc < r; rc++) {
		int n = N;
		while(n >= 8 || n == 4) {
			n -= 4;
			strcpy(S, p4, 4, rr*N+n, rc*N+n, (rr+rc)%2);
		}
		if(n == 3) strcpy(S, p3, 3, rr*N, rc*N, (rr+rc)%2);
		if(n == 5) strcpy(S, p5, 5, rr*N, rc*N, (rr+rc)%2);
		if(n == 7) strcpy(S, p7, 7, rr*N, rc*N, (rr+rc)%2);
	}
	for(int i = 0; i < r*N; i++) cout << S[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing

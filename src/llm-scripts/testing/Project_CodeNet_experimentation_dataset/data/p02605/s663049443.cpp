#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl "\n"
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define sz(s)    (int)(s.size())
#define PI acos(-1)
#define EPS 1e-8
#define watch(x) cout << (#x)<<" = "<<x<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("street.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
#define x first
#define y second
#define r 0
#define l 1
#define u 2
#define d 3
const int N = 2e5 + 9;
vi dia[N + N + 9][2][4];
vi arr[N][4];
int gt(char ch) {
	if (ch == 'R') return r;
	if (ch == 'L') return l;
	if (ch == 'U') return u;
	if (ch == 'D') return d;
}
int main() {
	file();
	fast();
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char ch; int xx, yy;
		cin >> xx >> yy >> ch;
		int g = gt(ch);
		dia[yy - xx + N][l][g].push_back(yy);
		dia[yy + xx][r][g].push_back(yy);
		if (g == l || g == r) arr[yy][g].push_back(xx);
		else arr[xx][g].push_back(yy);
	}
	
	for (int i = 0; i < N + N; i++)
		for (int j = 0; j < 4; j++)
			sort(all(dia[i][l][j])), sort(all(dia[i][r][j]));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			sort(all(arr[i][j]));
	
	int ans = INT_MAX;
	// on the same horizonatl
	for (int i = 0; i < N; i++) {
		for (auto& it : arr[i][r]) {
			auto bs = lower_bound(all(arr[i][l]), it);
			if (bs != arr[i][l].end())
				ans = min(ans, (*bs - it) * 5);
		}
	}
	// on the same vertically
	for (int i = 0; i < N; i++) {
		for (auto& it : arr[i][u]) {
			auto bs = lower_bound(all(arr[i][d]), it);
			if (bs != arr[i][d].end())
				ans = min(ans, (*bs - it) * 5);
		}
	}

	// from r or l to d
	for (int i = 0; i < N + N; i++) {
		for (auto& it : dia[i][l][r]) {
			auto bs = lower_bound(all(dia[i][l][d]), it);
			if (bs != dia[i][l][d].end())
				ans = min(ans, (*bs - it) * 10);
		}
		for (auto& it : dia[i][r][l]) {
			auto bs = lower_bound(all(dia[i][r][d]), it);
			if (bs != dia[i][r][d].end())
				ans = min(ans, (*bs - it) * 10);
		}
	}
	// from u to r or l
	for (int i = 0; i < N + N; i++) {
		for (auto& it : dia[i][l][u]) {
			auto bs = lower_bound(all(dia[i][l][l]), it);
			if (bs != dia[i][l][l].end())
				ans = min(ans, (*bs - it) * 10);
		}
		for (auto& it : dia[i][r][u]) {
			auto bs = lower_bound(all(dia[i][r][r]), it);
			if (bs != dia[i][r][r].end())
				ans = min(ans, (*bs - it) * 10);
		}
	}
	if (ans == INT_MAX)
		RT("SAFE\n");
	cout << ans << endl;
	return 0;
}
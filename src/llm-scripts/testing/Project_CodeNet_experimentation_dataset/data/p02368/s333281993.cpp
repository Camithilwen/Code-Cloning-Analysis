# include <iostream>
# include <algorithm>
#include <array>
# include <cassert>
#include <cctype>
#include <climits>
#include <numeric>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
#include <stdio.h>
#include<time.h>
#include <stdlib.h>
#include <cstdint>
#include <cfenv>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
long long MOD = 1000000000 + 7;// 998244353;// ;
constexpr long long INF = numeric_limits<LL>::max() / 2;
const double PI = acos(-1);
#define fir first
#define sec second
#define thi third
#define debug(x) cerr<<#x<<": "<<x<<'\n'
typedef pair<LL, LL> Pll;
typedef pair<LL, pair<LL, LL>> Ppll;
typedef pair<LL, pair<LL, bitset<100001>>> Pbll;
typedef pair<LL, pair<LL, vector<LL>>> Pvll;
typedef pair<LL, LL> Vec2;
struct Tll { LL first, second, third; };
struct Fll { LL first, second, third, fourd; };
typedef pair<LL, Tll> Ptll;
#define rep(i,rept) for(LL i=0;i<rept;i++)
#define Rrep(i,mf) for(LL i=mf-1;i>=0;i--)
void YN(bool f) {
	if (f)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
void yn(bool f) {
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
struct Edge { LL to, cost; };
struct edge { LL from, to, cost; };
vector<vector<LL>>g;
vector<edge>edges;
vector<LL>v;
map<LL, LL>ma;
set<Pll>st;
LL h, w, n, m, k, t, s, p, q, last, cnt, sum, ans, dp[210000],a[210000], b[210000];
string str, ss;
bool f;
char c;
vector<LL> kossaraju(vector<vector<LL>>&g) {
	LL n = g.size();
	vector<vector<LL>>rev(n);
	vector<LL>ret(n);
	vector<LL>ver;
	vector<bool>used(n);
	function<void(LL)>dfs1 = [&](LL cur) {
		used[cur] = 1;
		rep(i, g[cur].size()) {
			if (!used[g[cur][i]])
				dfs1(g[cur][i]);
		}
		ver.push_back(cur);
	};
	function<void(LL, LL)>dfs2 = [&](LL cur, LL root) {
		used[cur] = 1;
		ret[cur] = root;
		rep(i, rev[cur].size()) {
			if (!used[rev[cur][i]])
				dfs2(rev[cur][i], root);
		}
	};
	rep(i, n) rep(j, g[i].size()) rev[g[i][j]].push_back(i);
	rep(i, n) if (!used[i])dfs1(i);
	rep(i, n) used[i] = 0;
	Rrep(i, n)if (!used[ver[i]])dfs2(ver[i], ver[i]);
	return ret;
}
int main() {
	cin >> n>>m;
	g.resize(n);
	rep(i, m) {
		LL x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	vector<LL>V = kossaraju(g);
	cin >> q;
	rep(i, q) {
		LL x, y;
		cin >> x >> y;
		if (V[x] == V[y])cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}

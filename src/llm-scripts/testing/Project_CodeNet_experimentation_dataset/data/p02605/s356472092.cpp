#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF ((1<<25)-1)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()


int N;
int X[200000];
int Y[200000];
char U[200000];


int dir(char c) {
	return c == 'U' ? 0 : c == 'R' ? 1 : c == 'D' ? 2 : 3;
}

int near(int v, const set<int> &s) {
	int ret = INF;
	auto it = s.lower_bound(v);
	if (it != s.end()) {
		ret = min(ret, *it - v);
	}

	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int ans = INF;

	cin >> N;
	rep(i, N)cin >> X[i] >> Y[i] >> U[i];


	{
		unordered_map<int, array<set<int>, 4>> d;
		rep(i, N) {
			int a = X[i];
			d[a][dir(U[i])].insert(Y[i]);
		}
		// U, D
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('U')]) {

				ans = min(ans, near(y, layer[dir('D')]) * 5);
 			}
		}
	}
	{
		unordered_map<int, array<set<int>, 4>> d;
		rep(i, N) {
			int a = Y[i];
			d[a][dir(U[i])].insert(X[i]);
		}
		// L, R
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('R')]) {
				ans = min(ans, near(y, layer[dir('L')]) * 5);
			}
		}
	}


	{
		unordered_map<int, array<set<int>, 4>> d;
		rep(i, N) {
			int a = X[i] + Y[i];
			d[a][dir(U[i])].insert(Y[i]);
		}

		// R, U
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('U')]) {
				ans = min(ans, near(y, layer[dir('R')]) * 10);
			}
		}
		// D, L
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('L')]) {
				ans = min(ans, near(y, layer[dir('D')]) * 10);
			}
		}
	}
	

	{
		unordered_map<int, array<set<int>, 4>> d;
		rep(i, N) {
			int a = X[i] - Y[i] + 200000;
			d[a][dir(U[i])].insert(Y[i]);
		}

		// L, U
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('U')]) {
				ans = min(ans, near(y, layer[dir('L')]) * 10);
			}
		}
		// D, R
		for (const auto& p : d) {
			const auto& layer = p.second;
			for (int y : layer[dir('R')]) {
				ans = min(ans, near(y, layer[dir('D')]) * 10);
			}
		}
	}

	if (ans == INF)cout << "SAFE" << endl;
	else cout << ans << endl;

	return 0;
}

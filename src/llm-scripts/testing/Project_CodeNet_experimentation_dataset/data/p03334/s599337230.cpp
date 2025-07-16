#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
long long bad[700][700] = {};
vector<pair<int,int>> vertexs[2][700][700];
int visited[2][700][700];
int coloring[2][700][700];
int main() {
	long long n, d[2];
	cin >> n;
	REP(q, 2) {
		cin >> d[q];
	}
	REP(itr, 2) {
		for (long long a = 0; a * a <= d[itr]; ++a) {
			long long b = sqrt(d[itr] - a * a);
			if (b * b + a * a != d[itr]) continue;
			for (int q = 0; q < 2 * n; ++q) {
				for (int j = 0; j < 2 * n; ++j) {
					if (bad[q][j] == 1) continue;
					int xe[4] = { 1,1,-1,-1 };
					int ye[4] = { 1,-1,1,-1 };
					REP(t, 4) {
						int now_x = q + xe[t] * a;
						int now_y = j + ye[t] * b;
						if (now_x >= 0 && now_x < 2 * n && now_y >= 0 && now_y < 2 * n) {
							if (bad[now_x][now_y] == 1) continue;
							vertexs[itr][q][j].push_back(make_pair(now_x, now_y));
							vertexs[itr][now_x][now_y].push_back(make_pair(q, j));
						}
					}
				}
			}
		}
		for (int q = 0; q < 2 * n; ++q) {
			for (int j = 0; j < 2 * n; ++j) {
				if (visited[itr][q][j] == 0 && bad[q][j] == 0) {
					queue<pair<int, int>> next;
					next.push(make_pair(q, j));
					visited[itr][q][j] = 1;
					vector<pair<int, int>> used;
					int cnt[2] = {};
					while (next.empty() == false) {
						pair<int, int> now = next.front();
						next.pop();
						used.push_back(now);
						REP(i, vertexs[itr][now.first][now.second].size()) {
							pair<int, int> going = vertexs[itr][now.first][now.second][i];
							if (visited[itr][going.first][going.second] == 0) {
								visited[itr][going.first][going.second] = 1;
								coloring[itr][going.first][going.second] = (coloring[itr][now.first][now.second] + 1) % 2;
								cnt[coloring[itr][going.first][going.second]]++;
								next.push(going);
							}
						}
					}
					int yusen = 1;
					if (cnt[0] < cnt[1]) {
						yusen = 0;
					}
					REP(q, used.size()) {
						if (coloring[itr][used[q].first][used[q].second] == yusen) {
							bad[used[q].first][used[q].second] = 1;
						}
					}
				}
			}
		}
	}
	int cnt = 0;
	REP(q, 2 * n) {
		REP(j, 2 * n) {
			if (bad[q][j] == 0) {
				cnt++;
				if (cnt <= n * n) {
					cout << q << " " << j << endl;
				}
			}
		}
	}
}
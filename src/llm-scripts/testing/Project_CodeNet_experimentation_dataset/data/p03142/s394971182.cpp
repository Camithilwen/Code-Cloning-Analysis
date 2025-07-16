#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
vector<vector<int>> vec(100010);
int co[100010] = { 0 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1 + m; i++) {
		int a, b;
		cin >> a >> b;
		co[b]++;
		vec[a].emplace_back(b);
	}
	queue<int>que;
	for (int i = 1; i <= n; i++) {
		if (co[i]==0) {
			que.push(i);
			break;
		}
	}
	int ans[100010] = { 0 };
	while (!que.empty()) {
		int k = que.front();
		for (int l = 0; l < vec[k].size(); l++) {
			co[vec[k][l]]--;
			if (co[vec[k][l]] == 0) {
				que.push(vec[k][l]);
			}
			ans[vec[k][l]] = k;
		}
		que.pop();
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}


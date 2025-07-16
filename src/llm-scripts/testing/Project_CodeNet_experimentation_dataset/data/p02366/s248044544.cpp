
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

//??°?????????lowlink???????????????????????¢????????¨??????????????????
//?¨??????? O(|V|+|E|)
void lowlink(vector<int>graph[], int n, vector<int>&low, vector<pair<int, int>>&br, vector<int>&jnt) {
	low.resize(n);
	vector<int>ord(n);//DFS?????????
	vector<bool>vis(n);//?¨???????????????????
	//?????°????????????
	function<void(int, int, int&)>dfs = [&](int v, int p, int &k) {
		vis[v] = true;
		ord[v] = k++;
		low[v] = ord[v];
		bool joint = false;
		int cnt = 0;
		for (auto nxt : graph[v]) {
			if (!vis[nxt]) {
				cnt++;
				dfs(nxt, v, k);
				low[v] = min(low[v], low[nxt]);
				if (p >= 0 && ord[v] <= low[nxt]) joint = true;
				if (ord[v] < low[nxt])br.push_back({ min(v,nxt),max(v,nxt) });
			}
			else if (nxt != p) {
				low[v] = min(low[v], ord[nxt]);
			}
		}
		if (p < 0 && cnt > 1) joint = true;
		if (joint) jnt.push_back(v);
	};
	int k = 0;
	for (int i = 0; i < n; ++i)
		if (!vis[i])dfs(i, -1, k);
}

int N, M;
vector<int>graph[123456];

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
		graph[t].push_back(s);
	}
	vector<int>low, jnt;
	vector<pair<int, int>>br;
	lowlink(graph, N, low, br, jnt);
	sort(jnt.begin(), jnt.end());
	for (int i : jnt) {
		cout << i << endl;
	}
	return 0;
}
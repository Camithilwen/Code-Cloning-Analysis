#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> graph[100001];
int ans[100001];
signed main() {
    //Ввод графа и вершины start.
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	int Q, K;
	cin >> Q >> K;
    for (int i = 0; i < n; i++) {
        ans[i] = LONG_MAX;
    }
    int start = K - 1;
    ans[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, start});

    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();

        int dst = c.first, v = c.second;

        if (ans[v] < dst) {
            continue;
        }

        for (pair<int, int> e: graph[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < ans[u]) {
                ans[u] = n_dst;
                q.push({n_dst, u});
            }
        }
    }
    for (int i = 1; i <= Q; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	cout << ans[u] + ans[v] << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;

int ord[100010], low[100010];
int k;
vector<int> G[100010];
vector<pair<int, int>> bridge;
vector<int> articulation;
bool visit[100010] = {};

void dfs(int v, int p, int &k) {
    visit[v] = 1;
    ord[v] = k++;
    low[v] = ord[v];

    bool isArticulation = 0;
	int ct = 0;
    for (int i = 0; i < G[v].size(); i++) {
        if (!visit[G[v][i]]) {
            ct++;
            dfs(G[v][i], v, k);
            low[v] = min(low[v], low[G[v][i]]);
            if (~p && ord[v] <= low[G[v][i]]) isArticulation = 1;
            if (ord[v] < low[G[v][i]]) 
                bridge.emplace_back(min(v, G[v][i]), max(v, G[v][i]));
        }
        else if (G[v][i] != p) {
            low[v] = min(low[v], ord[G[v][i]]);
        }
    }
    if (p == -1 && ct > 1) isArticulation = 1;
	if (isArticulation) articulation.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    int k = 0;
	for (int i = 0; i < n; i++){
		if (!visit[i]) dfs(i, -1, k);
	}
    sort(bridge.begin(), bridge.end());
	sort(articulation.begin(), articulation.end());

    for (int i = 0; i < bridge.size(); i++) {
        //cout << bridge[i].first << " " << bridge[i].second << endl;
    }
    for (int i = 0; i < articulation.size(); i++) {
        cout << articulation[i] << endl;
    }
}

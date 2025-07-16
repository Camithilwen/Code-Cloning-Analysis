#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> P;
#define int long long
#define ll long long
#define mod 1000000007
#define INF (1LL<<60)


void bfs(int s, vector<vector<int>>& g, vector<int>& visited){
	queue<int> q;
	q.push(s);
	visited[s] = s;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int v : g[u]){
			if (visited[v] < 0){
				visited[v] = s;
				q.push(v);
			}
		}
	}
}

signed main(){

	int N, K, L;
	vector<vector<int>> road, train;
	cin >> N >> K >> L;
	road.assign(N, vector<int>());
	train.assign(N, vector<int>());
	for (int i = 0; i < K; i++){
		int p, q;
		cin >> p >> q; p--; q--;
		road[p].push_back(q);
		road[q].push_back(p);
	}
	for (int i = 0; i < L; i++){
		int p, q;
		cin >> p >> q; p--; q--;
		train[p].push_back(q);
		train[q].push_back(p);
	}

	vector<int> visited_road(N), visited_train(N);
	visited_road.assign(N, -1);
	visited_train.assign(N, -1);

	for (int i = 0; i < N; i++){
		if (visited_road[i] < 0) bfs(i, road, visited_road);
		if (visited_train[i] < 0) bfs(i, train, visited_train);
	}

	map<pair<int, int>, int> cnt;
	for (int i = 0; i < N; i++){
		cnt[pair<int, int>(visited_road[i], visited_train[i])]++;
	}

	for (int i = 0; i < N; i++){
		cout << cnt[pair<int, int>(visited_road[i], visited_train[i])] << " ";
	}


	return 0;
}

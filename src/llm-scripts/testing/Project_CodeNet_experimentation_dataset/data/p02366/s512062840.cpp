#include<iostream>
#include<list>
#include<queue>
#include<set>
#include<algorithm>
#include<stdio.h>
using namespace std;
int n, m;
struct Node {
	//int id;
	list<int> next;
};
Node graph[100005];
int prenum[100005];
int parent[100005];
int lowest[100005];
set<int> answer;
int rootCount;
void dfs(int curNodeId,int step) {
	int low = prenum[curNodeId];
	list<int>::iterator it = graph[curNodeId].next.begin();
	list<int>::iterator end = graph[curNodeId].next.end();
	for (it; it != end; it++) {
		int id = *it;
		if (prenum[id] == 0) {
			parent[id] = curNodeId;
			prenum[id] = step + 1;
			dfs(id, step + 1);
			low = min(low, lowest[id]);
			if (step == 1) {
				rootCount++;
			}
		}
		else {
			low = min(low, prenum[id]);
		}
	}
	lowest[curNodeId] = low;
}
void findArticulationPoint() {
	if (rootCount >= 2) {
		answer.insert(0);
	}
	int p;
	for (int i = 1; i < n; i++) {
		p = parent[i];
		if (p == 0) {
			continue;
		}
		if (prenum[p] <= lowest[i]) {
			answer.insert(p);
		}
	}
	vector<int> ans;
	for (set<int>::iterator it = answer.begin(); it != answer.end(); it++) {
		ans.push_back(*it);
	}

	sort(ans.begin(), ans.end());

	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		printf("%d\n", *it);
	}
}
int main() {
	scanf("%d %d", &n,&m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a,&b);
		graph[a].next.push_back(b);
		graph[b].next.push_back(a);
	}

	prenum[0] = 1;
	dfs(0,1);

	findArticulationPoint();

	/*for (int i = 0; i < n; i++) {
		cout << i << " " << prenum[i] << " " << parent[i] << " " << lowest[i] << endl;
	}*/
}


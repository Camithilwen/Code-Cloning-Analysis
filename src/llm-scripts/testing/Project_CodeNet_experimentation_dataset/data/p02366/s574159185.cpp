#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

static const int MAX = 100000;

int n, num;
vector<int> V[MAX];
int prenum[MAX], lowest[MAX], parent[MAX];
bool B[MAX];

void dfs(int cur, int pre) { //dfs??¨?????????prenum, lowest, parent????¨????
	prenum[cur] = lowest[cur] = num++;
	B[cur] = true;

	int next;
	for (int i = 0; i < V[cur].size(); i++) {
		next = V[cur][i];
		if (!B[next]) {
			parent[next] = cur;
			dfs(next, cur);
			lowest[cur] = min(lowest[cur], lowest[next]); //?????????????°?????????????????°????????????°??????
		} else if (next != pre) {
			lowest[cur] = min(lowest[cur], prenum[next]); //back-edge
		}
	}
}

void artPoint() {
	set<int> ap;
	int np = 0;
	for (int i = 1; i < n; i++) {
		int p = parent[i];
		if (p == 0) np++; //root?????\?¶???????????????°
		else if (prenum[p] <= lowest[i]) {
			ap.insert(p);
		}
	}
	if (np > 1) ap.insert(0);
	for (set<int>::iterator it = ap.begin(); it != ap.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	int e;
	cin >> n >> e;
	int s, t;
	for (int i = 0; i < e; i++)	{
		cin >> s >> t;
		V[s].push_back(t);
		V[t].push_back(s);
	}

	for (int i = 0; i < n; i++)	{
		B[i] =  false;
	}

	num = 1;
	dfs(0, -1); //next?????¶???prev???????????????

	artPoint();

	return 0;
}
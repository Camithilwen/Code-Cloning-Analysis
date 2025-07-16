#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N, M, K, A, B, C, D[100000], vis[100000];
map<int, vector<pair<int,bool>>>v[100000];
queue<int>q;


void dfs(int x, int a, int t) {
	vector<pair<int,bool>>&V = v[x][a];
	for (int i = 0; i < V.size(); ++i) {
		if (!V[i].second) {
			V[i].second = true;
			if (D[V[i].first] == t + 1 && vis[V[i].first] != a) {
				vis[V[i].first] = a;
				dfs(V[i].first, a, t);
			}
			if (D[V[i].first] == -1) {
				D[V[i].first] = t + 1;
				q.push(V[i].first);
				dfs(V[i].first, a, t);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	while (M--) {
		cin >> A >> B >> C;
		--A;
		--B;
		v[A][C].push_back(mkp(B, false));
		v[B][C].push_back(mkp(A, false));
	}
	memset(D, -1, sizeof D);
	D[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto it = v[x].begin(); it != v[x].end(); ++it) {
			dfs(x, it->first, D[x]);
		}
	}
	cout << D[N - 1] << endl;
}

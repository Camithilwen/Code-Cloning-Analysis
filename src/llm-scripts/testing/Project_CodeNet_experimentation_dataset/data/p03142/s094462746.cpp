#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int n, m;

#define MAXN (1 << 17)
#define INF (1 << 30)

vector<int> a[MAXN];
vector<int> rev[MAXN];
int p[MAXN];
int v[MAXN]; 
int f[MAXN];

int curt;

void dfs(int cur) {
	v[cur] = 1;
	curt++;
	for (int i = 0; i < a[cur].size(); i++) {
		int nnext = a[cur][i];
		if (!v[nnext]) {
			dfs(nnext);
		}
	}
	curt++;
	f[cur] = curt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n + m - 1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		rev[t2].push_back(t1);
		p[t2] = t1;
	}

	int s = 1;
	while (p[s]) {
		s = p[s];
	}
	dfs(s);
/*	for (int i = 1; i <= n; i++) {
		cerr << f[i] << " ";
	}	
	cerr << endl;
*/	for (int i = 1; i <= n; i++) {
		int best = INF;
		int bestind = 0;
		for (int j = 0; j < rev[i].size(); j++) {
			int nnext = rev[i][j];
			if (f[nnext] < best) {
				best = f[nnext];
				bestind = nnext;
			}
		}
		cout << bestind << endl;
	}

	return 0;
}

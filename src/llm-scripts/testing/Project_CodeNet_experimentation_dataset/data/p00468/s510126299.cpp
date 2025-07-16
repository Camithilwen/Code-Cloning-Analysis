#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
	int n, m;
	vector<vector<int> > f;
	for (;;) {
		scanf("%d %d", &n, &m);
		if (!n && !m) break;
		f = vector<vector<int> >(n + 1);
		rep(i, m) {
			int a, b;
			scanf("%d %d", &a, &b);
			f[a].push_back(b);
			f[b].push_back(a);
		}

		set<int> friends, friends_2;
		friends.insert(1);
		friends_2.insert(1);
		rep(i, f[1].size()) friends.insert(f[1][i]);

		for (auto ff : friends) {
			rep(i, f[ff].size()) friends_2.insert(f[ff][i]);
		}

		printf("%d\n", friends_2.size() - 1);
	}

	return 0;
}
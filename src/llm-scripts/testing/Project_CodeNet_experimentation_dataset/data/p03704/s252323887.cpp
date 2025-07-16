#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<cmath>
#include<unordered_set>
#define int long long
using namespace std;

int ans;
int n;
vector<int>V;
int S = 1;
void DFS(int sum, int a) {//今a番目まで見て合計がsum
	if (a == V.size()) {
		if (sum == n) {
			ans += S;
		}
		return;
	}
	int b = 0;
	for (int c = a + 1; c < V.size(); c++) {
		b += V[c];
	}
	b *= 9;
	for (int i = -9; i <= 9; i++) {
		int d = sum + V[a] * i;
		if (abs(d - n) <= b) {
			int e = abs(i);
			e = 10 - e;
			if (i >= 0 && a == 0) {
				e--;
			}
			if (e == 0)return;
			S *= e;
			DFS(d, a + 1);
			S /= e;
		}
	}
}
signed main() {
	cin >> n;
	for (int i = 2; i <= 18; i++) {
		V.clear();
		int a = 1, b = pow(10, (i - 1));
		for (int j = 0; j < i / 2; j++) {
			V.push_back(b - a);
			a *= 10; b /= 10;
		}
		if (i & 1) {
			S *= 10;
		}
		DFS(0, 0);
		if (i & 1) {
			S /= 10;
		}
	}
	cout << ans << endl;
}
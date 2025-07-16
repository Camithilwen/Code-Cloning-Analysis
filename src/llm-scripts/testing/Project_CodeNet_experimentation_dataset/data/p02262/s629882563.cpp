#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1111111], c, g[20];
int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	g[0] = 1; c = 0;
	while(true) {
		g[c + 1] = g[c] * 3 + 1;
		if(g[++c] >= n) break;
	}
	int ret = 0;
	for(int i = c - 1; i >= 0; i--) {
		for(int j = g[i]; j < n; j++) {
			int v = a[j], w = j - g[i];
			while(w >= 0 && a[w] > v) {
				a[w + g[i]] = a[w];
				w -= g[i];
				ret++;
			}
			a[w + g[i]] = v;
		}
	}
	cout << c << endl;
	for(int i = c - 1; i >= 0; i--) {
		if(i) cout << g[i] << ' ';
		else cout << g[i] << endl;
	}
	cout << ret << endl;
	for(int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
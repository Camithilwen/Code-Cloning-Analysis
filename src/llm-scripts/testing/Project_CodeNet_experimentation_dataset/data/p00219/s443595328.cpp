#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int g[10];
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			g[x]++;
		}
		for (int i = 0; i < 10; i++) {
			if (g[i] == 0) cout << '-' << endl;
			else {
				cout << string(g[i], '*') << endl;
			}
		}
	}
	return 0;
}
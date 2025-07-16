// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1, j = m + 1; i < j; i++, j--)
		cout << i << ' ' << j << '\n';
	for (int i = m + 2, j = m + m + 1; i < j; i++, j--)
		cout << i << ' ' << j << '\n';
	return 0;
}

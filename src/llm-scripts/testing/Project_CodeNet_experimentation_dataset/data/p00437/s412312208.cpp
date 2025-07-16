#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c, a | b | c) {
		int N;
		cin >> N;
		vector<int> res(a + b + c, 2);
		vector<vector<int>> no;
		for (int i = 0; i < N; i++) {
			int x, y, z, t;
			cin >> x >> y >> z >> t; x--, y--, z--;
			if (t) {
				res[x] = res[y] = res[z] = 1;
			}
			else {
				no.push_back(vector<int>({ x, y, z }));
			}
		}
		for (auto t : no) {
			int x = t[0], y = t[1], z = t[2];
			if (res[x] == 1 && res[y] == 1) {
				res[z] = 0;
			}
			else if (res[y] == 1 && res[z] == 1) {
				res[x] = 0;
			}
			else if (res[z] == 1 && res[x] == 1) {
				res[y] = 0;
			}
		}
		for (int i = 0; i < a + b + c; i++) {
			cout << res[i] << endl;
		}
	}
	return 0;
}


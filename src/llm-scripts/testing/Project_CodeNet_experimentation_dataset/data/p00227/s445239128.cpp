#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	while(cin >> n >> m, n || m) {
		vector<int> v;
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp; v.push_back(tmp);
		}
		sort(v.rbegin(), v.rend());
		int res = 0;

		for(int i = 0; i < v.size(); i++) {
			if((i+1) % m)
				res += v[i];
		}
		cout << res << endl;
	}
}
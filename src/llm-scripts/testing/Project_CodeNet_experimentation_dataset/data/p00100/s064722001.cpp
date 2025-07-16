# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;

int main() {
	int n;
	while (cin >> n&&n) {
		long long member[4001] = {};
		bool flag[4001] = {};
		for (int i = 1; i <= 4000; i++) {
			member[i] = 0;
			flag[i] = false;
		}
		long long a, b, c;
		int count = 0;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			member[a] += b*c;
			if (member[a] >= 1000000&&!flag[a]) {
				count++;
				flag[a] = true;
				cout << a << endl;
			}
		}
		if (count == 0)cout << "NA" << endl;
	}
}
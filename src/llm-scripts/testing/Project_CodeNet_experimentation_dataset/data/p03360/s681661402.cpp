#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	
	vector<int> x = {a, b, c};
	int ans = 0;
	for(int i = 0; i < k; ++i) {
		sort(x.begin(), x.end());
		x[2] *= 2;
	}
	
	cout << accumulate(x.begin(), x.end(), 0) << endl;
	
	return 0;
}

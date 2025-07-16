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
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string a;
	cin >> a;
	
	int n = (int)a.size();
	map<char, int> mp;
	
	for(int i = 0; i < n; ++i) {
		mp[a[i]]++;
	}
	
	ll ans = 1LL;
	for(int i = 0; i < n; ++i) {
		ans += n - i - 1 - (mp[a[i]] - 1);
		mp[a[i]]--;
	}
	
	cout << ans << endl;
	
	return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int s, n, i, j, k, ans, ct;
	cin >> s >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());

	vector<bool> v(s);
	ans = 0;
	ct = a[0];
	for (i = 0; i < s; i += 2) {
		if (ct > 0) {
			v[i] = true;
			ct--;
		}
	}

	for (i = s - 1; i >= 0; i--) {
		if (!v[i] && (ct > 0)) {
			v[i] = true;
			ct--;
		}
	}

	ans = 0;
	for (i = 1; i < s; i++) {
		if (v[i] && (v[i - 1])) ans++;
	}

	
	cout << ans << "\n";

	return 0;
}

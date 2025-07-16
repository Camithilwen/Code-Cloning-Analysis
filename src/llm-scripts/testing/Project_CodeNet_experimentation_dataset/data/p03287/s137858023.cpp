#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
set<pair<long long, long long>> st;
long long sum = 0;
int main() {
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	st.insert(make_pair(0, 1));
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		sum = (sum + a) % m;
		pair<long long, long long> pa;
		if (st.lower_bound(make_pair(sum, 0)) != st.end()) {
			pa = *st.lower_bound(make_pair(sum, 0));
			if (sum == pa.first) {
				ans += pa.second;
				st.erase(*st.lower_bound(make_pair(sum, 0)));
				st.insert(make_pair(sum, pa.second + 1));
			}
			else {
				st.insert(make_pair(sum, 1));
			}
		}
		else {
			st.insert(make_pair(sum, 1));
		}
	}
	cout << ans << endl;
	return 0;
}
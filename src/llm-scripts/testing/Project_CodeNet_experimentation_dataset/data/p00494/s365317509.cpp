#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	string st; cin >> st;
	int ans = 0;
	for (int l = 0; l < st.size(); ++l) {
		if (st[l] == 'O') {
			int r = l;
			while (r!=st.size()&&st[r] == 'O') {
				r++;
			}
			int len = r - l;
			if (l - len >= 0 && r + len <= st.size()) {
				bool ok = true;
				for (int t = 0; t < len; ++t) {
					if (st[l - t - 1] != 'J')ok = false;
					if (st[r + t] != 'I')ok = false;
				}
				if (ok)ans = max(ans, len);
			}
			l += len - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
	
int main() {
	int n;
	cin >> n;
	int a[n], b[n], c[n], d[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> d[i];
	}

	int blue_XtoY[205];
	int red_XtoY[205];

	memset(blue_XtoY, -1, sizeof(blue_XtoY));
	memset(red_XtoY, -1, sizeof(red_XtoY));

	for (int i = 0; i < n; i++) {
		blue_XtoY[c[i]] = d[i];
		red_XtoY[a[i]] = b[i];
	}
	
	int ans = 0;
	set<int> st;
	for (int right = 200; right >= 0; right--) {
		if (red_XtoY[right] != -1) {
			if (st.lower_bound(red_XtoY[right]) != st.end()) {
				ans++;
				st.erase(*st.lower_bound(red_XtoY[right]));
			}
		}
		if (blue_XtoY[right] != -1) {
			st.insert(blue_XtoY[right]);
		}
	}
	
	cout << ans << endl;
	return 0;
}
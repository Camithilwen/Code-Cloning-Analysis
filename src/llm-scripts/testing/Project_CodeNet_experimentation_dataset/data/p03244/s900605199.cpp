#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	if (n == 2) {
		int o, e; cin >> o >> e;
		if (o == e) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	const int p = n / 2;
	const int z = 100001;
	vector<int> o_num(z, 0), e_num(z, 0);
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		if (i % 2 == 0) o_num[v]++;
		else e_num[v]++;
	}
	int o_firstCnt = 0;
	int o_secondCnt = 0;
	int o_firstCntValue = 0;	
	int e_firstCntValue = 0;
	int e_firstCnt = 0;
	int	e_secondCnt = 0;
	for (int i = 0; i < z; i++) {
		if (o_firstCnt <= o_num[i]) {
			o_firstCntValue = i;
			o_firstCnt = o_num[i];
		}
		if (e_firstCnt <= e_num[i]) {
			e_firstCntValue = i;
			e_firstCnt = e_num[i];
		}
	}
	sort(o_num.rbegin(), o_num.rend());
	sort(e_num.rbegin(), e_num.rend());
	o_firstCnt = o_num[0];
	o_secondCnt = o_num[1];
	e_firstCnt = e_num[0];
	e_secondCnt = e_num[1];
	int ans;
	if (o_firstCntValue != e_firstCntValue) {
		ans = n - o_firstCnt - e_firstCnt;
	}
	else { // o_firstCntValue == e_firstCntValue
		ans = min(n - o_secondCnt - e_firstCnt, n - o_firstCnt - e_secondCnt);
	}
	cout << ans << endl;
	return 0;
}
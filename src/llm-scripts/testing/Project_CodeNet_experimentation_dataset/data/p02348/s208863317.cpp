#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair
using namespace std;
int t, n, q, l = 0, r = 123456, x = 2147483647, q1;
pair<int, int>t1[123456], t2[12345], t3[1234], t4[123], t5[12];
void f1() {
	r++;
	while (l < r) {
		if (l % 10000 == 0 && l + 10000 <= r) {
			t5[l / 10000] = mp(t, x);
			l += 10000;
		}
		else if (l % 1000 == 0 && l + 1000 <= r) {
			t4[l / 1000] = mp(t, x);
			l += 1000;
		}
		else if (l % 100 == 0 && l + 100 <= r) {
			t3[l / 100] = mp(t, x);
			l += 100;
		}
		else if (l % 10 == 0 && l + 10 <= r) {
			t2[l / 10] = mp(t, x);
			l += 10;
		}
		else {
			t1[l] = mp(t, x); l++;
		}
	}
}
int f2(int i) {
	int t = t1[i].first, x = t1[i].second;
	i /= 10;
	if (t < t2[i].first) {
		t = t2[i].first; x = t2[i].second;
	}
	i /= 10;
	if (t < t3[i].first) {
		t = t3[i].first; x = t3[i].second;
	}
	i /= 10;
	if (t < t4[i].first) {
		t = t4[i].first; x = t4[i].second;
	}
	i /= 10;
	if (t < t5[i].first) {
		t = t5[i].first; x = t5[i].second;
	}
	return x;
}
signed main() {
	cin >> n >> q;
	for0(i, n)t1[i] = mp(0, x);
	for (t = 1; t <= q; t++) {
		cin >> q1;
		if (q1) {
			int i; cin >> i; cout << f2(i) << endl;
		}
		else {
			cin >> l >> r >> x;	f1();
		}
	}
}

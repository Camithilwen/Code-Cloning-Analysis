#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int n, q, s, t, x, u;
iP a[1<<18];
bool b;

int update(int s, int t, int x, int k, int l, int r, int i) {
	if (t < l || r < s)return 0;
	else if (s <= l&&r <= t) {
		a[k] = mkp(x, i);
		return 0;
	}
	else {
		update(s, t, x, k * 2, l, (l + r) / 2, i);
		update(s, t, x, k * 2 + 1, (l + r) / 2 + 1, r, i);
		return 0;
	}
}
int find(int x) {
	int y, z = -2;
	x += u;
	while (x) {
		if (z < a[x].second) {
			y = a[x].first;
			z = a[x].second;
		}
		x /= 2;
	}
	return y;
}


int main(){
	cin >> n >> q;
	for (int i = 1;; ++i) {
		if ((1 << i) / n >= 2) {
			u = (1 << i - 1);
			break;
		}
	}
	for (int i = 1; i != u * 2; ++i)
		a[i] = mkp(intmax, -1);
	for (int i = 0; i != q; ++i) {
		cin >> b >> s;
		if (b) {
			cout << find(s) << endl;
		}
		else {
			cin >> t >> x;
			update(s, t, x, 1, 0, u - 1, i);
		}
	}
	return 0;
}


#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

std::string substrBack(std::string str, size_t pos, size_t len) {
	const size_t strLen = str.length();

	return str.substr(strLen - pos, len);
}

int main()
{
	int n;
	cin >> n;
	vector<ll> al(n);
	vector<ll> bl(n);
	vector<ll> cl(n);
	rep(i, n) {
		cin >> al[i];
	}
	rep(i, n) {
		cin >> bl[i];
	}
	rep(i, n) {
		cin >> cl[i];
	}
	sort(al.begin(), al.end());
	sort(bl.begin(), bl.end());
	sort(cl.begin(), cl.end());

	ll ans = 0;
	/*rep(i, n) {
		auto lb = upper_bound(bl.begin(), bl.end(), al[i]);
		ll lbStart = lb - bl.begin();
		ll tmp = 0;
		for (int j = lbStart; j < cl.size(); j++)
		{
			auto cb = upper_bound(cl.begin(), cl.end(), bl[j]);
			tmp += cl.size() - (cb - cl.begin());
		}
		ans += tmp;
	}*/
	rep(i, n) {
		auto la = lower_bound(al.begin(), al.end(), bl[i]) - al.begin();
		auto lc = cl.size() - (upper_bound(cl.begin(), cl.end(), bl[i]) - cl.begin());
		ans += la * lc;
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}



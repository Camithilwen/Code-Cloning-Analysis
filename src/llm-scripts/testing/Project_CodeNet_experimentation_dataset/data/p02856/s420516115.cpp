#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const ll MAX = 1e9 + 5;

int main() {
	int m;
	cin >> m;
	vector<int> d(m);
	vector<ll> c(m);

	for (int i = 0; i < m; i++) {
		cin >> d[i] >> c[i];
	}

	vector<vector<pll>> dl(10);

	for (int i = 0; i < 10; i++) {
		dl[i].emplace_back(make_pair(i, 0));
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 60; j++) {

			//cout << j << endl;
			ll num = dl[i][j].first * 2;
			ll cnt = dl[i][j].second * 2 + 1;
			

			if (num >= 10) {
				cnt++;
				num = num % 10 + 1;
			}
			dl[i].emplace_back(make_pair(num, cnt));
		}
		//cout << i << endl;
	}

	/*
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 60; j++) {
			cout << dl[i][j].first << " ";// << dl[i][j].second << endl;
		}
		cout << endl;
	}
	*/

	ll cnt = 0;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		int num = 0;
		cnt--;
		for (int b = 0; b < 60; b++) {
			
			if (((c[i] >> b) & 1) == 1) {
				num += dl[d[i]][b].first;
				cnt += dl[d[i]][b].second;
				cnt++;
				//cout << i << " " << dl[d[i]][b].second << " " << dl[d[i]][b].first << endl;
			}
			if (num >= 10) {
				num -= 9;
				cnt++;

			}
		}

		a[i] = num;

	}
	//cout << cnt << endl;
	int num = a[0];
	for (int i = 1; i < m; i++) {
		//cout << a[i] << endl;
		num += a[i];
		cnt++;
		if (num >= 10) {
			num -= 9;
			cnt++;

		}
	}

	cout << cnt << endl;
}
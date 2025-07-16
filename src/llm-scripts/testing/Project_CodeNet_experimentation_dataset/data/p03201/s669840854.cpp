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
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m[a]++;
	}

	int cnt = 0;
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		ll p2 = 1;
		ll num = it->first;
		while (p2 <= num) {
			p2 *= 2;
		}

		//cout << num << endl;
		
		auto it1 = m.find(p2 - num);
		if (it1 != m.end()) {
			
			if (it1->first == num) {
				cnt += it->second / 2;
			}
			else {
				int c = min(it1->second, it->second);
				it1->second -= c;
				cnt += c;

				if (it1->second == 0) {
					m.erase(it1);
				}

			}
			
			
		}
	}
	cout << cnt << endl;
}
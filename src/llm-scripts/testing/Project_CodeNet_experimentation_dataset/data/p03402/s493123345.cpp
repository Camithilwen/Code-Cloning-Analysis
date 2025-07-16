#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
const long long MOD = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ll> pdl;
typedef pair<ld, ld> pdd;
//typedef boost::multiprecision::cpp_int bigint;

ll A, B;

int main() {
	cin >> A >> B;
	vector<vector<ll>> MAP;   //1->黒 0->白
	MAP.resize(100, vector<ll>(100, 0));
	if (A > 1) {
		ll x = 0;
		for (ll c = 0; c < floor((ld)(A - 1) / 50); c++, x += 2) {
			for (ll y = 0; y < 100; y += 2) {
				MAP[x][y + 1] = 1;
				MAP[x + 1][y] = 1;
				MAP[x + 1][y + 1] = 1;
			}
		}
		for (ll y = 0; y < (A - 1) % 50; y++) {
			MAP[x + 1][2 * y + 1] = 1;
			MAP[x + 1][2 * y] = 1;
			MAP[x][2 * y + 1] = 1;
		}
		x += 3;
		for (ll b = 2; b <= B; x += 2) {
			for (ll y = 0; y < 100 && b <= B; b++, y += 2) {
				MAP[x][y] = 1;
			}
		}
		cout << "100 100" << endl;
		for (ll y = 0; y < 100; y++) {
			for (ll x = 0; x < 100; x++) {
				if (MAP[x][y])cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
	}
	else {
		for (ll b = 1,x = 1; b <= B; x += 2) {
			for (ll y = 0; y < 100 && b <= B; b++, y += 2) {
				MAP[x][y] = 1;
			}
		}
		cout << "100 100" << endl;
		for (ll y = 0; y < 100; y++) {
			for (ll x = 0; x < 100; x++) {
				if (MAP[x][y])cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
	}
	return 0;
}
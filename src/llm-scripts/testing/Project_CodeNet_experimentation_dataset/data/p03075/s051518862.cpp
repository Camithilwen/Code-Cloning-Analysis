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
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;



int main() {
	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int k;
	cin >> k;
	if (abs(v[0] - v[4]) <= k) {
		cout << "Yay!" << endl;
	}
	else {
		cout << ":(" << endl;
	}

}

#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}


ll a[100009];


int main() {
	set<ll> A;
	vector<ll> B;
	ll N;
	cin >> N;
	rep(i, N) {
		ll a;
		cin >> a;
		if (A.count(a)) {
			B.push_back(a);
			A.erase(a);
		}
		else {
			A.insert(a);
		}

	}
	if (B.size() < 2) {
		cout << 0 << endl;
		return 0;
	}

	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	cout << B.at(0) * B.at(1) << endl;
}
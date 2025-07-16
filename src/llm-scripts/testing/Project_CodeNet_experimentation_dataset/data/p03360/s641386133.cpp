#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
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
#include <math.h>
using namespace std;

int main() {
	vector<long long> num(3);
	long long K;
	for (int i = 0; i < 3; i++) {
		cin >> num.at(i);
	}
	sort(num.begin(), num.end());
	cin >> K;
	for (int i = 0; i < K; i++) {
		num.back() *= 2;
	}
	long long ans;
	ans = num.at(0) + num.at(1) + num.at(2);
	cout << ans << endl;
}
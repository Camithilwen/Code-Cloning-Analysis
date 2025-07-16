
#include <iostream>
#include <numeric>
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}





int main() {
	ll N,D=0;
	cin >> N ;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> W(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i)>>B.at(i);
		W.at(i)= A.at(i) + B.at(i);
		D -= (B.at(i));
	}
	sort(W.begin(), W.end());
	reverse(W.begin(), W.end());
	rep(i, (N+1)/2) {
		D += W.at(i*2);
	}

	cout << D << endl;

	
	
}
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
ll kai(vector<ll> A, ll key) {
	ll an = 0;
	rep(i, A.size()) {
		an += (A.at(i) - 1) / key;
	}
	return an;
}
// index が条件を満たすかどうか
bool isOK(int index,vector<ll> A, int K) {
	if (kai(A,index) <= K) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(ll MA,vector<ll> A,ll K) {
	int left = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = MA; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, A,K)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}
vector<ll> fact, factinv, inv;
ll mod = 1e9 + 7;
void prenCkModp(ll n) {
	fact.resize(n + 5);
	factinv.resize(n + 5);
	inv.resize(n + 5);
	fact.at(0) = fact.at(1) = 1;
	factinv.at(0) = factinv.at(1) = 1;
	inv.at(1) = 1;
	for (ll i = 2; i < n + 5; i++) {
		fact.at(i) = (fact.at(i - 1) * i) % mod;
		inv.at(i) = mod - (inv.at(mod % i) * (mod / i)) % mod;
		factinv.at(i) = (factinv.at(i - 1) * inv.at(i)) % mod;
	}

}
ll nCk(ll n, ll k) {
	return fact.at(n) * (factinv.at(k) * factinv.at(n - k) % mod) % mod;
}
ll HP[4];
int main() {
	ll H, W, A, B,an=0;
	cin >> H >> W >> A >> B;
	prenCkModp(H + W);
	for (ll i = 1; i <= H - A; i++) {
		an += (nCk(i + B-2, i-1) * nCk(H - i + W - B-1, W - B-1)) % mod;
	}
	cout << an % mod << endl;
}

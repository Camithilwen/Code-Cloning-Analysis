// Author : Harshdeep Sharma , IIT Indore
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #define MOD  998244353
#define ll long long
const double PI = atan(1.0) * 4;
// const ll INF = (int)1e9 ;
const int di[4] = { -1, 0, 1, 0} ;
const int dj[4] = {0, -1, 0, 1} ;
const ll INF = (ll)2e18 + 50;
const int maximum  = numeric_limits<int>::min();
const int minimum  = numeric_limits<int>::max();

// function to calculate any numbered power of some number without modulo
ll power(ll a , ll e) {
	ll res = 1LL ;
	while (e > 0) {
		if (e % 2 == 1) res = res * a;
		a =  a * a  ;
		e /= 2 ;
	}
	return res ;
}
// function to check whether a bracketed sequence is balanced or not
bool isBalanced(const string &exp) {
	// Initialising Variables
	bool flag = true;
	int count = 0;

	// Traversing the Expression
	for (int i = 0; i < exp.length(); i++) {

		if (exp[i] == '(') {
			count++;
		}
		else {
			count--;
		}
		if (count < 0) {
			flag = false;
			break;
		}
	}
	if (count != 0) {
		flag = false;
	}

	return flag;
}
// function to sort by second in a set of pairs
bool sortbysec(const pair<pair<int, int>, int> &a,
               const pair<pair<int, int>, int> &b) {
	return (a.second < b.second);
}

void uniformly_distribute_k_numbers_in_a_square_grid(int n , int k ) {
	int p = 0 , q = 0 ;
	vector<vector<int>> a(n, vector<int>(n)) ;
	for (int i = 1 ; i <= k ; ++i ) {
		a[p][q] = 1 ;
		p = p + 1 ;
		q = (q + 1) % n ;
		if (p == n) {
			p = 0  ;
			q = (q + 1) % n ;

		}
	}
}

ll f(ll n) {
	ll res ;
	if (n % 2 != 0) {
		ll pairs = (n + 1) / 2 ;
		if (pairs % 2 == 0) {
			res = 0  ;
		} else {
			res = 1 ;
		}
	} else {
		// cout << "i\n";
		ll pairs = n / 2 ;
		if (pairs % 2 == 0) {
			res = 0  ;
		} else {
			res = 1 ;
		}
		res ^= n ;
	}
	return res ;
}



// main funtion
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t ;
	// cin >> t ;
	// while (t--) {

	int n  , l ;
	cin >> n >> l ;
	int total = 0 ;
	int mn = 500 ;
	for (int i = 0 ; i < n ; i++) {
		total += (l + i) ;
		mn = min(mn , abs(l + i)) ;
	}
	// cout << total << " " << mn << "\n";
	if (total > 0) cout << total - mn << "\n";
	else cout << total + mn << "\n";








	// }







	return 0 ;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = INT64_MAX;

ll dp[100], bstX[35000][20], bstY[35000][20];

vector<vector<ll>> gr, psh;
vector<set<ll>> s;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

set<ll> ss;

void debug() {
	debug();
}

vector<ll> vec;

bool solve() {
	vector<ll> pr, suf;
	pr.push_back(0);
	suf.push_back(0);
	ll cnt = 0, val = 0, s = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 1) {
			cnt++;
			val = vec[i];
		}
		pr.push_back(gcd(pr.back(), vec[i]));
		s += vec[i] - 1;
	}

	if (cnt == 0) return false;
	if (cnt == 1 && val == 2) return true;
	for (int i = vec.size() - 1; i >= 0; i--) {
		suf.push_back(gcd(suf.back(), vec[i]));
	}

	reverse(suf.begin(), suf.end());

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 1) continue;
		ll g = gcd(pr[i], suf[i + 1]);
		g = gcd(g, vec[i] - 1);
		if (g != 1) {
			vec[i]--;
			for (int j = 0; j < vec.size(); j++) {
				vec[j] /= g;
			}
			bool k = solve();
			for (int j = 0; j < vec.size(); j++) {
				vec[j] *= g;
			}
			vec[i]++;
			if (!k) return true;
		}
	}

	if (s % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	fastInp;

	ll n;
	cin >> n;

	vec.resize(n);

	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		s += vec[i] - 1;
	}
	
	if (n % 2 == 0) {
		if (s % 2 == 0) {
			cout << "Second";
		}
		else {
			cout << "First";
		}
	}
	else {
		if (s % 2 == 0) {
			if (solve()) {
				cout << "First";
			}
			else {
				cout << "Second";
			}
		}
		else {
			cout << "First";
		}
	}

	return 0;
}
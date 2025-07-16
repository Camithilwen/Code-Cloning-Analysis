#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);
ll dx[] = { 1, 0 , -1,  0 }, dy[] = { 0, 1, 0, -1 };
ll cb(ll a, ll b);

int main() {
	string x;
	cin >> x;

	stack<char> s;
	ll n = x.size();

	rep(i, n) {
		if (s.size() == 0 || x[i] == 'S') s.push(x[i]);
		else if (s.top() == 'S' && x[i] == 'T') s.pop();
		else if (s.top() != 'S' && x[i] == 'T') s.push(x[i]);
	}

	cout << s.size();

	return 0;
}


ll cb(ll a, ll b) {
	ll ans = 1;
	rep(i, b) ans *= (a - i);
	rep(i, b) ans /= (b - i);

	return ans;
}

ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
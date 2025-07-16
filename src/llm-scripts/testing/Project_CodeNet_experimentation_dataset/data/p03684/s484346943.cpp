#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t[101];
int pri[26];
int res = 0;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}
void solv() {

	int n;
	cin >> n;
	uini(n);
	pair<ll, int> xr[100010];
	pair<ll, int> yr[100010];
	for (size_t i = 1; i <= n; i++)
	{
		ll x, y;
		cin >> x >> y;
		xr[i] = pair<ll, int>(x, i);
		yr[i] = pair<ll, int>(y, i);
	}

	sort(xr, xr + n + 1);
	sort(yr, yr + n + 1);
	map<ll, vector<pair<int, int>>> mx;
	for (int i = 2; i <= n; i++)
	{
		ll rem = abs( xr[i].first - xr[i - 1].first);
		mx[rem].push_back(pii(xr[i].second, xr[i - 1].second));

		ll remy = abs(yr[i].first - yr[i - 1].first);
		mx[remy].push_back(pii(yr[i].second, yr[i - 1].second));
	}
	ll res = 0;
	for (map<ll, vector<pii>>::iterator i = mx.begin(); i != mx.end(); i++)
	{
		ll val = i->first;
		vector<pii> v = i->second;
		for (int j = 0; j < v.size(); j++)
		{
			if (unit(v[j].first, v[j].second)) {
				res += val;
			}
		}
	}
	cout << res << endl;
}


int main() {
	solv();

	return 0;
}

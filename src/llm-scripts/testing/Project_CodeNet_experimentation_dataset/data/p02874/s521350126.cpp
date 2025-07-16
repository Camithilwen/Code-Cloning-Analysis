#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N; cin >> N;
	vector<pair<ll,ll>> ran(N);
	vector<ll> u(2), v(2,1e10);
	for (int i = 0; i < N; i++) {
		cin >> ran[i].first >> ran[i].second;
		if (u[0] < ran[i].first) {
			swap(u[0], u[1]);
			u[0] = ran[i].first;
		}
		else if (u[1] < ran[i].first)u[1] = ran[i].first;
		if (v[0] > ran[i].second) {
			swap(v[0], v[1]);
			v[0] = ran[i].second;
		}
		else if (v[1] > ran[i].second)v[1] = ran[i].second;

	}

	sort(ran.begin(), ran.end());
	vector<pair<ll, ll>> left(N);
	left[0] = ran[0];
	for (int i = 1; i < N; i++) {
		left[i].first = ran[i].first;
		left[i].second = min(left[i - 1].second, ran[i].second);
	}

	vector<pair<ll, ll>> right(N);
	right[N - 1] = ran[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		right[i].first = right[i + 1].first;
		right[i].second = min(right[i + 1].second, ran[i].second);
	}

	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ll temp = max((ll)0, left[i].second - left[i].first + 1);
		temp += max((ll)0, right[i + 1].second - right[i + 1].first + 1);
		ans = max(ans, temp);
		//cout << "i=" << i << " temp=" << temp << endl;
	}
	if (u[0] < u[1])swap(u[0], u[1]); //cout << "u[0]=" << u[0] << " u[1]=" << u[1] << endl;
	if (v[0] > v[1])swap(v[0], v[1]); //cout << "v[0]=" << v[0] << " v[1]=" << v[1] << endl;
	for (int i = 0; i < N; i++) {
		ll p = (ran[i].first != u[0] ? u[0] : u[1]), q = (ran[i].second != v[0] ? v[0] : v[1]);
		ans = max(ans, max((ll)0, q - p + 1) + ran[i].second - ran[i].first + 1);
		//cout << "i=" << i << " ans=" << ans ;
		//cout << " p=" << p << " q=" << q << endl;
	}
	cout << ans << endl;
}

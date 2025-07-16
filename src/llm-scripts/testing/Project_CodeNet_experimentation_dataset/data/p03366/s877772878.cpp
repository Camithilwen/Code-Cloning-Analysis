#include <bits/stdc++.h>
using namespace std;

int n, s, x, p;
deque<pair<int, long long> > d;

long long amx(int a) {
	if(s >= d.back().first) {
		return s - d.front().first;
	} else if(s <= d.front().first) {
		return d.back().first - s;
	}
	int na;
	long long D = d.back().first - d.front().first;
	if(d.front().second >= d.back().second) {
		pair<int, long long> t = d.front();
		t.second += d.back().second;
		d.pop_back();
		d.pop_front();
		d.push_front(t);
		na = 0;
	} else {
		pair<int, long long> t = d.back();
		t.second += d.front().second;
		d.pop_front();
		d.pop_back();
		d.push_back(t);
		na = 1;
	}
	return amx(na) + (long long)(a != na) * D;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) {
		cin >> x >> p;
		d.push_back({x, p});
	}
	cout << amx(2) << endl;
	return 0;
}

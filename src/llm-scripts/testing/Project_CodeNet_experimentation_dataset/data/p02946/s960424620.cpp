#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

template<typename T, typename Q>
istream &operator>>(istream &is, pair<T, Q> &p) {
	return is >> p.first >> p.second;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

template<typename T, typename Q>
ostream &operator<<(ostream &os, pair<T, Q> p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
	os << "[";
	for (auto it = v.begin(); it != v.end(); it++)
		os << (it == v.begin() ? "" : ", ") << *it;
	return os << "]";
}

template<typename T, typename Q>
ostream &operator<<(ostream &os, map<T, Q> m) {
	os << "[";
	for (auto it = m.begin(); it != m.end(); it++) 
		os << (it == m.begin() ? "" : ", ") << *it;
	return os;
}
#define imie(...) " [" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int mn = -1000000;
	int k, x; cin >> k >> x;
	set<int> s;
	if (x - k + 1 < mn) {
		for (int i = mn; i <= mn + k - 1; i++) {
			s.insert(i);
		}
		for (int i = x; i <= x + k - 1; i++) {
			s.insert(i);
		}
	} else if (x + k - 1 > -mn) {
		for (int i = -mn; i >= -mn - k + 1; i--) {
			s.insert(i);
		}
		for (int i = x; i >= x - k + 1; i--) {
			s.insert(i);
		}
	} else {
		for (int i = x; i <= x + k - 1; i++) {
			s.insert(i);
		}
		for (int i = x; i >= x - k + 1; i--) {
			s.insert(i);
	 	}
	}
	for (auto x : s) cout << x << " ";
}

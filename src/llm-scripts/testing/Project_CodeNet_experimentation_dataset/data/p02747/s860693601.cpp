#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	string s;
	bool hi = true;
	cin >> s;
	if(s.size() % 2 == 1)hi = false;
	else {
		for (int i = 0; i < s.size(); i += 2) {
			if (s.substr(i, 2) != "hi") hi = false;
		}
	}

	if (hi) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}

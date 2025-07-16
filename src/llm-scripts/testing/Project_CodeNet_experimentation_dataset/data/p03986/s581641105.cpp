#pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s, t;
	cin >> s;
	for(auto i : s) {
		if(i == 'S') t.pb(i);
		else if(t.size() && t.back() == 'S') t.pop_back();
		else t.pb(i);
	}
	cout << t.size();
}

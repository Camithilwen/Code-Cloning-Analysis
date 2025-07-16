#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool check(vector<P> s){
	int h = 0;
	for(P p : s){
		int b = h + p.first;
		if(b < 0) return false;
		h += p.second;
	}
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<P> ls, rs;
	int total = 0;
	rep(i,n){
		string s;
		cin >> s;
		int h = 0, b = 0;
		for(char c : s){
			if(c == '(') ++h;
			else --h;
			chmin(b, h);
		}
		if(h > 0) ls.emplace_back(b, h);
		else rs.emplace_back(b-h, -h);
		total += h;
	}
	sort(ls.rbegin(), ls.rend());
	sort(rs.rbegin(), rs.rend());
	if(check(ls) && check(rs) && total == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
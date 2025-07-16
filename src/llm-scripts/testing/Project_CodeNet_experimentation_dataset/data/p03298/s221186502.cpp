#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

void cal(string s, string x, string y, map<pair<string, string>, ll>& a) {
	if(sz(s) == 0) {
		a[mp(x,y)]++;
		return;
	}
	cal(s.substr(1), x + s.substr(0,1), y, a);
	cal(s.substr(1), x, y + s.substr(0,1), a);
}

ll solve(string s, string t) {
	map<pair<string, string>, ll> a, b;
	string x,y;
	x = y = "";
	cal(s,x,y,a);
	cal(t,x,y,b);
	ll ret = 0;
	for(auto e : a) {
		auto key = e.F;
		if(b.find(key) != b.end()) {
			ret += e.S * b[key];
		}
	}
	return ret;
}



int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	string s;
	cin >> n >> s;
	string t = s.substr(n);
	reverse(all(t));
	cout << solve(s.substr(0,n), t) << '\n';
}
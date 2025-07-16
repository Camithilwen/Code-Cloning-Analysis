#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(ll i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int n;
string m = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findidx(char c) {
	rep(i, m.size())if(c == m[i]) return i;
}

void solve(void) {
	int k[110];
	string s;
	rep(i, n) cin >> k[i];
	cin >> s;
	string ans;
	rep(i, s.size()) {
		int idx = findidx(s[i]);
		idx = ((idx + 52) - k[i % n]) % 52;
		ans += m[idx];
	}
	cout << ans << endl;
}

int main(void) {
	// cout << m.size() << endl;
	while(1) {
		cin >> n;
		if(n == 0) break;
		solve();
	}
	return 0;
}
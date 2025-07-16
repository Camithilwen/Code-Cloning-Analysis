#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
//#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main() {
	string s, t = "JOI";
	cin >> s;
	s += 'X';
	int ans = 0, f = -1, now = 0, pre = 0;
	rep(i, 0, s.size()) {
		if (s[i] == t[f]) {
			now++;
		}
		else if (f == 0 && s[i] == t[1]) {
			pre = now;
			now = 1;
			f = 1;
		}
		else if (f == 1 && s[i] == t[2]) {
			if (pre < now) {
				f = -1;
			}
			else {
				f++;
				pre = now;
				now = 1;
			}
		}
		else if (f == 2 && s[i] != t[2]) {
			if (pre <= now) ans = max(ans, pre);
			f = -1;
		}
		else {
			f = -1;
		}
		if (f == -1 && s[i] == 'J') {
			f = 0;
			now = 1;
		}
	}
	cout << ans << endl;
}
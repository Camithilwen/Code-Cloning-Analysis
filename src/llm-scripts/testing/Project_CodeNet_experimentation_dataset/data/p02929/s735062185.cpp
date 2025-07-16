#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define vc vector
#define sz(v) (int)(v).size()
#define pb push_back
#define FF first
#define SS second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define pll pair<ll,ll>
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
typedef long double f80;
#define endl '\n'

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
char s[N];
bool x[N];

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	fr(i, 1, 2 * n) {
		cin >> s[i];
	}
	int ans = 1;
	fr(i, 1, n) {
		ans = (ans * 1LL * i) % mod;
	}
	s[0] = 'W';
	s[2 * n + 1] = 'W';
	fr(i, 0, 2 * n) {
		if(s[i] != s[i + 1])
			x[i] = 1;
	}
	int cl = 0, cr = 0, val = 0;
	bool pos = 1;
	fr(i, 1, 2 * n) {
		if(x[i - 1]) {
			cl++;
			val++;
		}
		else {
			x[i] ^= 1;
			cr++;
			if(!val) pos = 0;
			ans = (ans * 1LL * val) % mod;
			val--;
		}
	}
	if(!pos || (cl != cr && cl != n)) {
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}
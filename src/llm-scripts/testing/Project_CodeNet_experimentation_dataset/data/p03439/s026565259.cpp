#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	cout << 0 << endl;
	string s;
	cin >> s;
	if (s == "Vacant") return 0;
	vector<string> v(n);
	v[0] = s;
	int l = 0;
	int r = n;
	int p = (l+r)/2;
	cout << p << endl;
	while (cin >> s, s != "Vacant") {
		v[p] = s;
		int x = p - l - 1;
		int y = r - p - 1;
		if ((v[l] == s && x % 2 == 0) || (v[l] != s && x % 2 == 1)) {
			r = p;
			p = (l+r)/2;
		} else {
			l = p;
			p = (l+r)/2;
		}
		cout << p << endl;
	}
}
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

const ll MOD = 1e9+7;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	map<int, int> y;
	map<int, int> x;
	rep(i,0,n) {
		int a;
		cin >> a;
		y[a] = i;
	}
	rep(i,0,m) {
		int b;
		cin >> b;
		x[b] = i;
	}
	ll ret = 1;
	ll A = 0;
	ll B = 0;
	per(i,1,n*m+1) {
		bool flagy = (y.find(i) != y.end());
		bool flagx = (x.find(i) != x.end());
		if(flagy && flagx) {
			A++; B++;
		} else if(flagy) {
			ret = ret * B % MOD;
			A++;
		} else if(flagx) {
			ret = ret * A % MOD;
			B++;
		} else {
			ll loc = A * B - (ll)(n*m - i);
			ret = ret * loc % MOD;
		}
	}
	cout << ret << '\n';
}
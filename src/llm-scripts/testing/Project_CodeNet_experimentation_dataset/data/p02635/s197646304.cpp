#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 319;
const int MOD = 998244353;
ll dp[maxn][maxn][maxn];
string s; 
int k, ones, zeros;
vi numo, mino;

ll solve(int a, int b, int c){
	if(dp[a][b][c] != -1){
		return dp[a][b][c];
	}
	if(a == 0){
		return (b - c == numo[a]);
	}
	ll ans = 0;
	for(int i = 0; i <= b; i++){
		int nh = b - i; // i is in this column, nh in previous
		if(i - numo[a] > c) break;
		if(nh < mino[a-1]) continue;
		int nm = max(i - numo[a], 0);
		ans = (ans + solve(a-1,nh,c-nm))%MOD;
	}
	dp[a][b][c] = ans;
	//cout << a << " " << b << " " << c << " "  << dp[a][b][c] << endl;
	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> s;
	cin >> k;
	int n = sz(s);
	for(char c: s) if(c == '1') ones++;
	zeros = n - ones;
	rep(i,maxn) rep(j,maxn) rep(ii,maxn) dp[i][j][ii] = -1;
	numo.pb(0);
	for(char c: s){
		if(c == '1') numo.back()++;
		else numo.pb(0);
	}
	mino.resize(sz(numo));
	mino[0] = numo[0];
	for(int i = 1; i < sz(numo); i++){
		mino[i] = mino[i-1] + numo[i];
	}
	ll ans = 0;
	k = min(k, ones);
	rep(i,k+1){
		ans = (ans + solve(zeros,ones,i))%MOD;
	}
	cout << ans << endl;
	return 0;
}


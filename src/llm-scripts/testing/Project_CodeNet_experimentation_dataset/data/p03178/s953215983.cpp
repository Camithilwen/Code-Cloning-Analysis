#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
	std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll INF =  1LL << 60;
const int inf = 1 << 30;
int n, m, x, y,q;ll z, w=0, sum = 0, ans = 0;
const int MAX = 510000;
const int MOD = 1000000007;
int dp[10010][2][110];
int main(void) {
	string s; int d; cin >> s >> d;
	Fill(dp, 0);
	dp[0][1][0] = 1;
	rep(i, s.size()) {
		rep(j, d) {
			rep(k, 10) {
				dp[i + 1][0][(j + k) % d] += dp[i][0][j];
				dp[i + 1][0][(j + k) % d] %= MOD;
			}
			int Si = s[i] - '0';
			rep(k, Si) {
				dp[i + 1][0][(j + k) % d] += dp[i][1][j];
				dp[i + 1][0][(j + k) % d] %= MOD;
			}
			dp[i + 1][1][(j + Si) % d] = dp[i][1][j];
		}
	}cout << (dp[s.size()][0][0] + dp[s.size()][1][0] - 1 + MOD) %MOD << endl;
}
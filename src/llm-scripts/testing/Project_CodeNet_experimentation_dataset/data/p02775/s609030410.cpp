//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	string s;
	cin >> s;
	s = "0" + s;
	int dp[s.size()][2] = {};
	dp[0][0] = 0;
	dp[0][1] = 1;
	REP1(i, s.size()-1){
		int num = s[i] - '0';
		dp[i][0] = min(dp[i-1][0] + num, dp[i-1][1] + 10 - num);
		dp[i][1] = min(dp[i-1][0] + num + 1, dp[i-1][1] + 10 - (num + 1));
	}
	cout << dp[s.size()-1][0] << endl;
}
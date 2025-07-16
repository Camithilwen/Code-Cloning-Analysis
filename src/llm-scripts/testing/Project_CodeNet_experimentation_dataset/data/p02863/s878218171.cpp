#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int dp[3010][10000];
int main()
{
	int n, t;
	cin >> n >> t;
	vector<P> p(n);
	rep(i,n) cin >> p[i].first >> p[i].second; // 時間、美味しさ。
	SORT(p);
	int ans = 0;
	rep(i,n){
		rep(j,t){
			chmax(dp[i+1][j], dp[i][j]);
			int nj = j + p[i].first;
			if(nj < t)
			chmax(dp[i+1][nj], dp[i][j] + p[i].second);
		}
		int now = dp[i][t-1]+p[i].second; //
		chmax(ans,now);
	}
	cout << ans << endl;

}

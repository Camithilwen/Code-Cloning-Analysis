#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef priority_queue<int> PQ;
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
//#define mod 998244353
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));
//priority_queue<int,vector<int>, greater<int> > q2;

int dp1[310][90909] = { 0 };
int dp2[310][90909] = { 0 };

signed main(){
cin.tie(0);
ios::sync_with_stdio(false);

	int N, sum = 0;
	int mod = 998244353;
	cin >> N;
	VI A(N);
	REP(i, N) {
		cin >> A[i];
		sum += A[i];
	}

	dp1[0][0] = 1;
	REP(i, N) {
		REP(j, 90909) {
			if (j + A[i] < 90909) {
				dp1[i + 1][j + A[i]] += dp1[i][j];
				dp1[i + 1][j + A[i]] %= mod;
			}
			dp1[i + 1][j] += 2 * dp1[i][j];
			dp1[i + 1][j] %= mod;
		}
	}

	int x = 0;
	REP(j, 90909) {
		if (j * 2 >= sum) {
			x += dp1[N][j];
			x %= mod;
		}
	}

	dp2[0][0] = 1;
	REP(i, N) {
		REP(j, 90909) {
			if (j + A[i] < 90909) {
				dp2[i + 1][j + A[i]] += dp2[i][j];
				dp2[i + 1][j + A[i]] %= mod;
			}
			dp2[i + 1][j] += dp2[i][j];
			dp2[i + 1][j] %=mod;
		}
	}

	int y = (sum % 2 == 0) ? dp2[N][sum / 2] : 0;

	int ans = 1;
	REP(i, N) {
		ans *= 3;
		ans %= mod;
	}
	//cout << x << endl;
	//cout << y << endl;
	//cout << ans << endl;
	//cout << (ans-3*x+3*y)%mod << endl;
	ans = (ans - 3 * x + 8 * mod) % mod;
	ans += 3 * y;

	cout << ans % mod << endl;

	return 0;
}


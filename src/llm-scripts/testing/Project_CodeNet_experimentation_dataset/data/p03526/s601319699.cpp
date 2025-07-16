#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<P> hp1(n);
	REP(i,n) cin>>hp1[i].first>>hp1[i].second;
	vector<P> sorting(n);
	REP(i,n) {
		sorting[i].first=hp1[i].first+hp1[i].second;
		sorting[i].second=i;
	}
	sort(ALL(sorting));
	vector<P> hp(n);
	REP(i,n) {
		hp[i]=hp1[sorting[i].second];
	}
	vector<vector<ll>> dp(n,vector<ll>(n+1,INF*INF));
	dp[0][0]=0;
	dp[0][1]=hp[0].second;
	FOR(i,1,n) {
		REP(j,n+1) {
			if(j==0) dp[i][j]=0;
			else {
				if(hp[i].first>=dp[i-1][j-1]) dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+hp[i].second);
				else dp[i][j]=dp[i-1][j];
			}
		}
	}
	ll ret=0;
	REP(i,n+1) {
		if(dp[n-1][i]!=INF*INF) ret=i;
	}
	cout<<ret<<endl;
}


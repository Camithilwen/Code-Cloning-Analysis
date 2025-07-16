#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(ll I = int((B)-1); I >= int(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ll N,X;
	cin >> N >> X;
	vector<ll> S(N);
	FOR(i,0,N)cin>>S[i];
	SORT(S);
	REV(S);
	ll dp[N+2][X+1]={};
	dp[0][X]=1;

	FOR(i,0,N){
		FOR(j,0,X+1){
			(dp[i+1][j%S[i]] += dp[i][j])%=MOD;
			(dp[i+1][j] += dp[i][j]*(N-i-1))%=MOD;
		}
	}
	ll ans = 0;
	FOR(j,1,X+1){
		(ans += dp[N][j]*j)%=MOD;
	}
	cout << ans << endl;
}

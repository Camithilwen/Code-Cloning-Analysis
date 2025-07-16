#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 301;
const int mod = 998244353;
int n,a[nax];
int dp[nax][nax*nax];
int ans,sum,sub;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ans=1;
	for(int i=1; i<n;i++) {
		ans=((LL)ans*3)%mod;
	}
	dp[0][0] = 1;
	for(int i=1; i<=n;i++) {
		for(int s=0; s<=sum; s++) {
			dp[i][s] = (2*dp[i-1][s])%mod;
			if(s-a[i]>=0) {
				dp[i][s]= (dp[i][s]+dp[i-1][s-a[i]])%mod;
			}
		}
	}
	for(int i=1; i<=sum;i++) {
		if(i>=(sum+1)/2) {
			sub=(sub+dp[n][i])%mod;
		}
	}
	dp[0][0] = 1;
	for(int i=1; i<=n;i++) {
		for(int s=0; s<=sum;s++) {
			dp[i][s] = dp[i-1][s];
			if(s-a[i]>=0) {
				dp[i][s]= (dp[i][s]+dp[i-1][s-a[i]])%mod;
			}
		}
	}
	if(sum%2==0) {
		sub=(sub-dp[n][sum/2]+mod)%mod;
	}
	int res = (((ans-sub)%mod)+mod)%mod;
	res = ((LL)res*3)%mod;
	printf("%d",res);
}

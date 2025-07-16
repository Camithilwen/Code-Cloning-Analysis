#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int llint;
llint v[1000005],dp[1000005],n;
int x[25][25];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> x[i][j];
		}
	}
	for(int i=0;i<(1 << n);i++) {
		for(int j=0;j<n;j++) {
			for(int k=j+1;k<n;k++) {
				v[i]+=((i & (1 << j)) && (i & (1 << k)))*x[j][k];
			}
		}
	}
	for(int i=0;i<(1 << n);i++) {
		dp[i]=max(dp[i],v[i]);
		for(int j=i;j>0;j=(j-1) & i) {
			dp[i]=max(dp[i],dp[j]+dp[i ^ j]);
		}
	}
	cout << dp[(1 << n)-1];
	return 0;
}

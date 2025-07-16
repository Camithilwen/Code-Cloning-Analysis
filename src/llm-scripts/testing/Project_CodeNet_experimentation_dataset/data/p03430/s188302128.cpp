#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
string s,t;
int dp[310][310][310] = {};
int main(){
	int i,j,l,n,k;
	cin >> s >> k; n = s.size();
	for(i=0;i<n;i++){
		t.push_back(s[n - 1 - i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(l=0;l<=k;l++){
				if(s[i - 1]==t[j - 1]){
					dp[i][j][l] = dp[i - 1][j - 1][l] + 1;
				}else{
					int x = max(dp[i - 1][j][l],dp[i][j - 1][l]);
					if(l>0) x = max(x,dp[i - 1][j - 1][l - 1] + 1);
					dp[i][j][l] = x;
				}
			}
		}
	}
	int ans = 0;
	for(i=0;i<n;i++){
		ans = max(ans,2*dp[i][n - i][k]);
		ans = max(ans,2*dp[i][n - 1 - i][k] + 1);
	}
	cout << ans << endl;
}
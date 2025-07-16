#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repn(i,n,m) for(int i=n;i<m;i++)
#define repn1(i,n,m) for(int i=n;i<=m;i++)
using namespace std;

int main(){

	int dp[100] = {0};
	int n;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	repn1(i, 4, 30) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	while(cin >> n, n){

		cout << dp[n] / 3650 + (dp[n]%3650==0 ? 0 : 1) << endl;
	}

	return 0;
}
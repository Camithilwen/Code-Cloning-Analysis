#include<bits/stdc++.h>
using namespace std;
// Reference : Erichto + https://www.youtube.com/watch?v=1HiJ332iZQU
long double dp[301][301][301];

long double solve(int ones, int twos, int threes, int n) {
	// cout<<"At "<<ones <<" "<< twos <<" "<< threes<<endl;
	if(ones + twos + threes == 0) {
		// cout<<"Base:"<<0<<endl;
		return 0;
	}
	if(dp[ones][twos][threes] != -1) {
		// cout<<"Cache:"<<dp[ones][twos][threes]<<endl;
		return dp[ones][twos][threes];
	}
	long double coeff1 = (long double)ones / (long double)(ones + twos + threes);
	long double coeff2 = (long double)twos / (long double)(ones + twos + threes);
	long double coeff3 = (long double)threes / (long double)(ones + twos + threes);
	long double ans = (long double) n/ (long double) (ones + twos + threes);
	dp[ones][twos][threes] = ans + 
				coeff1 * (ones == 0 ? 0 : solve(ones - 1, twos, threes, n)) + 
				coeff2 * (twos == 0 ? 0 : solve(ones + 1, twos - 1, threes, n)) + 
				coeff3 * (threes == 0 ? 0 : solve(ones, twos + 1, threes - 1, n ));
	// cout<<"Returning" << dp[ones][twos][threes]<<endl;
	return dp[ones][twos][threes];
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	int cnt[4]={0};
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 0; i <= 300; ++i) {
		for(int j = 0; j <= 300; ++j) {
			for(int k = 0; k <= 300; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout<<fixed<<setprecision(20)<<solve(cnt[1], cnt[2], cnt[3], n);
}
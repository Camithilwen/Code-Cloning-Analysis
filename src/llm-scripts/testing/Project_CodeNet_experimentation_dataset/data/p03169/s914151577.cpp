#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

long double dp[301][301][301];
long double N;

long double solve(int ones, int twos, int threes){
	if(dp[ones][twos][threes] >= 0) return dp[ones][twos][threes];
	long double cur = 1;
	if(threes > 0) cur += (threes/N) * (solve(ones,twos+1,threes-1));
	if(twos > 0) cur += (twos/N) * (solve(ones+1,twos-1,threes));
	if(ones > 0) cur += (ones/N) * (solve(ones-1,twos,threes));
	cur *= N / (ones+twos+threes);
	return dp[ones][twos][threes] = cur;
}


void solution(){
	// expected value dp -- states are messed up, use top down to simplify implementation
	int n; cin >> n;
	N = (long double)n;
	vector<int> a(n); for(auto& x : a) cin >> x;
	int ones = 0, twos = 0, threes = 0;
	for(int x : a){
		if(x == 1) ones++;
		else if(x == 2) twos++;
		else threes++;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0] = 0;
	printf("%0.14Lf\n", solve(ones,twos,threes));
}	


int main(){ 

	fio; // fast input output
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// GOOGLE //
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}

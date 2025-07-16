#include <bits/stdc++.h>
using namespace std;

double solve(vector<vector<vector<double>>>& dp, int a, int b, int c, double N){
	if(dp[a][b][c] != 0){
		return dp[a][b][c];
	}
	if(a==0 && b==0 && c==0) return 0;
	double f = 0;
	f +=  1 / (1 - (N-a-b-c)/N );
	if(a>0) f += solve(dp,a-1,b,c, N)   * (a/N) /(1 - (N-a-b-c)/N );
	if(b>0) f += solve(dp,a+1,b-1,c, N) * (b/N) /(1 - (N-a-b-c)/N );
	if(c>0) f += solve(dp,a,b+1,c-1, N) * (c/N) /(1 - (N-a-b-c)/N );
	return dp[a][b][c] = f;

}

int main(){
	int N;
	cin >> N;
	vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(N+1,0)));
	int a=0, b=0, c=0;
	for(int i=0; i<N; i++){
		int t; cin >> t;
		if(t==1) a++;
		else if(t==2) b++;
		else c++;
	}
	printf("%.9lf\n",solve(dp,a,b,c,(double)N));
	return 0;
}


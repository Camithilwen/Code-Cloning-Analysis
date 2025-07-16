#include <bits/stdc++.h>
using namespace std;
struct hito{
	long long sum; 
	long long H; 
	long long P; 
}; 
bool cmp(const hito &a, const hito &b){
    return a.sum < b.sum;
}
int main(){
	int N; cin >> N; 
	long long INF = 1e18; 
	hito A[5010] = {}; 
	for(int i = 1; i <= N; i++){
		cin >> A[i].H >> A[i].P; 
		A[i].sum = A[i].H + A[i].P; 
	}
	sort(A+1, A+N+1, cmp); 
	long long dp[5010][5010] = {}; // dp[i人目まで見て][j人のときの最小の高さ] 
	for(int i = 0; i <= N; i++){
		for(int j = 1; j <= N+1; j++){
			dp[i][j] = INF; 
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(A[i].H >= dp[i-1][j-1]) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + A[i].P); 
			else dp[i][j] = dp[i-1][j]; 
		}
	}
	for(int i = 1; i <= N+1; i++){
		if(dp[N][i] == INF){
			cout << i-1 << endl; return 0; 
		}
	}
}
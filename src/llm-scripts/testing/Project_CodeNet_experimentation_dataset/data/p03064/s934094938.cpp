#include <bits/stdc++.h>
using namespace std; 
int main(){
	int N; 
	cin >> N; 
	long long int P = 998244353; 
	int A[310] = {}; 
	int S = 0; 
	for(int i = 1; i <= N; i++){
		cin >> A[i]; 
		S += A[i]; 
	}
	long long int dp[310][90010] = {}; // はじめi枚まででRがjになるようなRGBの組の個数
	dp[0][0] = 1; 
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= 300 * i; j++){
			if(j >= A[i]) dp[i][j] = (dp[i-1][j-A[i]] + dp[i-1][j] * 2) % P; 
			else dp[i][j] = (dp[i-1][j] * 2) % P; 
		}
    }
	long long int exceed = 0; 
	for(int i = (S + 1)/2; i <= S; i++){
		exceed += dp[N][i]; 
	}
	exceed = exceed % P; 
	dp[0][0] = 1; // はじめi枚まででRがjになるようなRの組の個を同じ配列で再計算
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= 300 * i; j++){
			if(j >= A[i]) dp[i][j] = (dp[i-1][j-A[i]] + dp[i-1][j]) % P; 
			else dp[i][j] = dp[i-1][j]; 
		}
    }
	long long int pow3[314] = {};
	pow3[0] = 1; 
	for(int i = 1; i <= 310; i++){
		pow3[i] = (pow3[i-1] * 3) % P; 
	}
	if(S % 2 == 1) cout << (3 * P + pow3[N] - exceed * 3) % P << endl; 
	else cout << (3 * P + pow3[N] + dp[N][S / 2] * 3- exceed * 3) % P << endl; 
}
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
	if(n == 2 || n == 3) return true; 
	if(n % 6 != 1 && n % 6 != 5) return false; 
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false; 
	}
	return true; 
}
int main(){
	vector<int> P;
	for(int i = 3; i < 10000; i+=2){
		if(is_prime(i)) P.push_back(i); 
	}
	long long A[1010][1010] = {}; 
	for(int i = 0; i <= 500; i++){
		for(int j = 0; j <= 500; j++){
			A[i*2][j*2] = P[i] * P[501+j]; 
		}
	}
	for(int i = 0; i <= 499; i++){
		for(int j = 0; j <= 499; j++){
			A[i*2+1][j*2+1] = A[i*2][j*2] * A[i*2+2][j*2+2] + 1; 
		}
	}
	long long ans[510][510] = {}; 
	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 500; j++){
			ans[i][j] = A[500-i+j][i+j]; 
		}
	}
	int N; cin >> N; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << ans[i][j] << " "; 
		}
		cout << endl; 
	}
}
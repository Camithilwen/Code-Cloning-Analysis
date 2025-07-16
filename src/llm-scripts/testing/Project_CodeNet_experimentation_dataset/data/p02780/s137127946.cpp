#include<bits/stdc++.h>
using namespace std;

long long N, K;
double P[200000]; 

int main(){
	cin >> N >> K;
	for(long long i = 0; i < N; i++) {
		double p;
		cin >> p;
		P[i] = (1.0 + p)/2.0;
	}

	double ans = 0;
	double sum = 0;
	for(long long i = 0; i < K; i++) {
		sum += P[i];
	}
	ans  = sum;

	for(long long i = K; i < N; i++) {
		sum += P[i];
		sum -= P[i-K];
		ans = max(ans, sum);
	}

	printf("%.10f\n", ans);




}

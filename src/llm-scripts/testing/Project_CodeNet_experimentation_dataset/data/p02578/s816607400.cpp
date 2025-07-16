#include <bits/stdc++.h>
using namespace std;
int main(){
	long long sum1 = 0;
	long long numbers[200000];
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> numbers[i];
	}
	for(int i = 0; i < N-1; ++i){
		if(numbers[i+1] < numbers[i]){
			sum1+=numbers[i] - numbers[i+1]; 
			numbers[i+1] = numbers[i+1] + (numbers[i] - numbers[i+1]);
		}

	}
	cout << sum1; 
}

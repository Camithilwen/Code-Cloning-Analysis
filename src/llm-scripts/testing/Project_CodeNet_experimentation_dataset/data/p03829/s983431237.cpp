#include <iostream>
using namespace std;

int main() {
	long long N, A, B;
	cin>>N>>A>>B;
	long long arr[N];
	for (int i=0; i<N; i++){
		cin>>arr[i];
	}
	long long sum=0;
	for (int i=0; i<N-1; i++){
		if (A*(arr[i+1]-arr[i])>B){
			sum += B;	
		}
		else sum += A*(arr[i+1]-arr[i]);
	}
	cout << sum << endl;
}
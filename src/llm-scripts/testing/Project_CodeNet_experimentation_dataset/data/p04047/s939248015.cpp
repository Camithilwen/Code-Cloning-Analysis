#include <bits/stdc++.h>
using namespace std;
#define int long long int




main() {
	int n;
	cin>>n;
	int arr[2*n];
	for(int i=0; i<2*n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+2*n);
	int sum=0;
	for(int i=0; i<2*n; i=i+2){
		sum+=arr[i];
	}
	cout<<sum;
	return 0;
}
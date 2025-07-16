#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long ret = 0;
	int neg = 0;
	vector<long long>arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]<0) neg++;
		ret+=abs(arr[i]);
		arr[i] = abs(arr[i]);
	}
	if(neg%2) ret-=2*(*min_element(arr.begin(),arr.end()));
	cout<<ret;
}
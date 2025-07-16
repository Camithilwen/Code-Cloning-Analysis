#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	for(int i=1; i<arr.size(); i++){
		if(arr[i-1]==arr[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}
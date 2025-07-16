#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++) arr[i]++;
	for(int i=1; i<n; i++) arr[i]+=arr[i-1];
	int maxsum = arr[k-1];
	for(int i=k; i<n; i++) maxsum = max(maxsum,arr[i]-arr[i-k]);
	cout<<maxsum/2<<".";
	if(maxsum%2) cout<<5;
	else cout<<0;
	cout<<"00000000";
}
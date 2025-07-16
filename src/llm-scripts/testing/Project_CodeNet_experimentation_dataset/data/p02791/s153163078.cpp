#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int before_min = arr[0];
	int ret = 0;
	for(int i=0; i<n; i++){
		before_min = min(before_min,arr[i]);
		if(before_min>=arr[i]) ret++;
	}
	cout<<ret;
}
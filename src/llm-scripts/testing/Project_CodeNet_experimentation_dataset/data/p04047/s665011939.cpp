#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin>>size;
	int arr[2*size]={};
	int ans=0;
	
	for(int i=0;i<2*size;i++){
	    cin>>arr[i];
	    
	}
	
	sort(arr,arr+2*size);
	for(int i=0;i<2*size;i++){
	    if(i%2==0){
	        ans=ans+arr[i];
	    }
	}
	cout<<ans;
	return 0;
}
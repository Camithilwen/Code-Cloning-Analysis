//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n,k;
	cin>>n>>k;
	int sum = 0;
	if(k < 0){
		int last = (n + k - 1);
		if(last>=0){
			for(int i=k;i<=last;i++)
				sum += i;
		}else{
			for(int i=k;i<last;i++){
				sum += i;
			}
		}
	}else{
		for(int i=k+1;i<n+k;i++){
			sum+=i;
		}
	}	

	cout<<sum<<endl;
	

	return 0;
}
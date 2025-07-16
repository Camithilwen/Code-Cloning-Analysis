#include<bits/stdc++.h>
using namespace std;

int main(){
	long long sum=0;
	int n;
	cin>>n;
	int mx;cin>>mx;n--;
	while(n--){
		int a;
		cin>>a;
		sum+=max(0,mx-a);
		mx=max(mx,a);
	}
	cout<<sum;
}
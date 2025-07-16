#include<bits/stdc++.h>
using namespace std;
int n,a[203],ans;
int main(){
	cin>>n;
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	sort(a,a+2*n);
	for(int i=0;i<2*n;i+=2)
		ans+=a[i];
	cout<<ans;
}
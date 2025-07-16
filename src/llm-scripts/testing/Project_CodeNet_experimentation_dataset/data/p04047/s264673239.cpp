#include<bits/stdc++.h>
using namespace std;
int n;
int a[225];
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	sort(a+1,a+2*n+1);
	int summ=0;
	for(int i=2*n;i>=1;i-=2){
		summ+=a[i-1];
	}
	cout<<summ;
}
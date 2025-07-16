#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[2*n];
	for(int i=0;i<2*n;i++)
	cin>>a[i];
	sort(a,a+2*n);
	int sum=0;
	for(int i=0;i<2*n-1;i+=2)
	sum+=min(a[i],a[i+1]);
	cout<<sum;
	
}
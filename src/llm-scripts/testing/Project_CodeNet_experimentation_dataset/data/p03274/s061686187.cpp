#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n+1];
	int b[n+1];
	int j=0;
	a[0]=0;
	b[0]=0;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=0)
		{
			j=i;
			break;
		}
		else
		a[i]*=(-1);
		if(i==n)
		{
			j=n;
			f=1;
		}
	}
	
	b[1]=a[j];
	int s=2;
	for(int i=j+1;i<=n;i++)
	{
		cin>>b[s];
		s++;
	}
	s--;
	if(f==0)
	j--;
	long long t=9999999999;
	sort(a+1,a+1+j);
	for(int i=max(0,k-s);i<=min(k,j);i++)
	{
		int p=0;
		p+=a[i];
		p+=b[k-i];
		p+=min(a[i],b[k-i]);
		if(p<t)
		{
			t=p;
		}
		
	}
	cout<<t;
 } 
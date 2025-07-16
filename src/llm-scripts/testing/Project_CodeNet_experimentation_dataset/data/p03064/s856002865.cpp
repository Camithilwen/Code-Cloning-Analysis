#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long tot=1,d[99001],e[99001],s=0;
int main()
{
	cin>>n;
	d[0]=e[0]=1;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		s+=x;
		tot=tot*3%mod;
		for(int j=s;j>=0;j--)
		{
			d[j]=(d[j]*2+(j>=x?d[j-x]:0))%mod;
			e[j]=(e[j]+(j>=x?e[j-x]:0))%mod;
		}
	}
	long long sum=0;
	for(int i=(s+1)/2;i<=s;i++)sum=(sum+d[i])%mod;
	cout<<((tot-3*sum+3*(s%2==0?e[s/2]:0))%mod+mod)%mod<<'\n';
}

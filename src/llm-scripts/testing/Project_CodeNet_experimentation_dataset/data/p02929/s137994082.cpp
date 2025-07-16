#include<iostream>
using namespace std;
int N;
string s;
long mod=1e9+7;
main()
{
	cin>>N>>s;
	long ans=1,cnt=0;
	for(int i=0;i<2*N;i++)
	{
		if(cnt%2==0)
		{
			if(s[i]=='B')
			{
				cnt++;
			}
			else
			{
				ans=ans*cnt--%mod;
			}
		}
		else
		{
			if(s[i]=='B')
			{
				ans=ans*cnt--%mod;
			}
			else
			{
				cnt++;
			}
		}
	}
	for(int i=1;i<=N;i++)ans=ans*i%mod;
	cout<<(cnt==0?ans:0)<<endl;
}

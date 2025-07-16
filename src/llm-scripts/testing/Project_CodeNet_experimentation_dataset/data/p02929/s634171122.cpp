#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<time.h>
#include<sstream>
#define MINN -1e8 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f3f3f;
const int P=1e9+7;
const int MAXN=32000;
const double pi=3.1415926;
const ll mod=1000000007;
int n;
ll ans=1;
char c[200005];
ll f(ll len)
{
	ll cur=1;
	for(ll i=1;i<=len;i++)
	{
		cur=cur*i%mod;
	}
	return cur; 
}
int main()
{
	cin>>n;getchar();
	ll tmp=1,len=1;
	for(int i=0;i<2*n;i++)c[i]=getchar();
	if(c[0]!='B'||c[n*2-1]!='B')
	{
		cout<<0;return 0;
	}
	for(int i=1;i<2*n-1;i++)
	{
		if(c[i]=='B')  
		{
			if(tmp%2==1)
			{
				ans=ans*tmp%mod;
				tmp--;len++;
			}
			else tmp++;
		}
		else 
		{
			if(tmp%2==1) tmp++;
			else
			{
				ans=ans*tmp%mod;
				tmp--;len++;
			}
		}
	}
	if(tmp!=1)
	{
		cout<<0;return 0;
	}
	else
	{
		ans=ans*f(len)%mod;
		cout<<ans;
	}
	return 0;
}
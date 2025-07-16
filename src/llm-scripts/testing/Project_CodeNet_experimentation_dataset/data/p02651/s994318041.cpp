#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=205;
int T;
int n;
long long a[N];
char s[N];
struct Basis
{
	static const int M=60;
	long long d[N];
	void clear()
	{
		memset(d,0,sizeof(d));
		return;
	}
	void insert(long long t)
	{
		for(int i=M;i>=0;i--)
			if(t&(1LL<<i))
			{
				if(d[i]) t^=d[i];
				else
				{
					for(int j=0;j<i;j++)
						if(t&(1LL<<j)) t^=d[j];
					for(int j=i+1;j<=M;j++)
						if(d[j]&(1LL<<i)) d[j]^=t;
					d[i]=t;
					break;
				}
			}
		return;
	}
	bool find(long long t)
	{
		for(int i=M;i>=0;i--)
			if(t&(1LL<<i))
			{
				if(d[i]) t^=d[i];
				else return false;
			}
		return true;
	}
}lb;
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%s",s+1);
	lb.clear();
	for(int i=n;i>=1;i--)
		if(s[i]=='1')
		{
			if(!lb.find(a[i]))
			{
				printf("1\n");
				return;
			}
		}
		else if(s[i]=='0') lb.insert(a[i]);
	printf("0\n");
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
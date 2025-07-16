#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1001000 
#define pb push_back 
int n,ans,pos[N],sum[N];
char s[N],p[N];
vector<int>ve[30];
vector<int>::iterator it;
int p1[N],p2[N],m;
bool check(int x)
{
	for(int i=1;i+x<=m;++i)
		if(p1[i+x]-x<p2[i])
			return false;
	return true;
}
int main()
{
	scanf("%d%s%s",&n,s+1,p+1);
	int i,last=n+1,flag=0,r;
	for(i=1;i<=n;++i) if(s[i]!=p[i]) flag=1;
	if(!flag) puts("0");
	else
	{
		flag=0;
		for(i=1;i<=n;++i) ve[s[i]-'a'].pb(i);
		for(r=i=n;i>=1;--i)
		{
			if(i==1||p[i-1]!=p[i])
			{
				last=min(last,i+1);
				it=lower_bound(ve[p[i]-'a'].begin(),ve[p[i]-'a'].end(),last);
				if(it==ve[p[i]-'a'].begin()) {flag=1; break;}
				--it;
				last=*it;
				++m;
				p1[m]=*it; p2[m]=r;
				r=i-1;
			}
		}
		if(flag) puts("-1");
		else
		{
			for(i=1;i<=m;++i) if(i<m+1-i) swap(p1[i],p1[m+1-i]),swap(p2[i],p2[m+1-i]);
			int l=0,mid; r=m;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(check(mid)) r=mid;
				else l=mid+1;
			}
			printf("%d",r);
		}
	}
	return 0;
}
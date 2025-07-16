#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const long long inf=0x3f3f3f3f;
long long bs[maxn];
long long d,dx1[maxn],dx2[maxn];
long long a[maxn],an,ans;
void dfs(long long x,long long v,long long c)
{
	if(x==an)
	{
		ans+=(v==d)*c;
		return ;
	}
	if(abs(v-d)>a[x]*20)
		return ;
	for(long long i=0;i<20;i++)
	{
		long long cnt;
		if(x==0)
			cnt=dx1[i];
		else
			cnt=dx2[i];
		if(a[x]==0)
			cnt=i<10;
		if(cnt==0)
			continue;
		dfs(x+1,v+(i-10)*a[x],c*cnt);
	}
}
void solve(long long n)
{
	an=0;
	for(long long i=0;i<n;i++)
	{
		if(i>n-i-1)
			break;
		a[an++]=bs[n-i-1]-bs[i];
	}
	dfs(0,0,1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    for(long long i=0;i<=9;i++)
    	for(long long j=0;j<=9;j++)
    		dx2[i-j+10]++;
    for(long long i=0;i<=9;i++)
    	for(long long j=1;j<=9;j++)
    		dx1[i-j+10]++;
    bs[0]=1;
    for(long long i=1;i<19;i++)
    	bs[i]=bs[i-1]*10;
    cin>>d;
    for(long long i=1;i<=19;i++)
    	solve(i);
    cout<<ans<<endl;
	return 0;
}

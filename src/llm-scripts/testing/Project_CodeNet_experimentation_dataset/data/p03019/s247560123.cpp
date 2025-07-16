#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar('0'+aa%10);
	return;
}
long long n,X,sum,ans;
long long b[100005],l[100005],r[100005],id[100005];
long long vis[100005];
long long F(long long aa)
{
	return (X-b[aa])*r[aa]+b[aa]*l[aa];
}
bool cmp(long long aa,long long bb)
{
	return F(aa)>F(bb);
}
int main()
{
	n=read(),X=read();
	for(long long i=1;i<=n;++i) b[i]=read(),l[i]=read(),r[i]=read(),id[i]=i,sum+=l[i]*b[i];
	if(sum==0) {puts("0");return 0;}
	sort(id+1,id+n+1,cmp);
	for(long long i=1;i<=n;++i)
	{
		if(sum>=F(id[i])) sum-=F(id[i]),ans+=X;
		else
		{
			sum-=F(id[i]);
			long long mx=X;
			for(long long j=1;j<=n;++j)
			{
				long long tmp=0;
				if(vis[j]) sum+=F(j);
				else sum+=F(id[i]);
				if(sum<=b[j]*l[j]) tmp=(sum-1)/l[j]+1;
				else sum-=b[j]*l[j],tmp=b[j]+(sum-1)/r[j]+1,sum+=b[j]*l[j];
				if(vis[j]) sum-=F(j);
				else sum-=F(id[i]);
				mx=min(tmp,mx);
			}
			ans+=mx;
			sum=0;
		}
		if(!sum) break;
		vis[id[i]]=1;
	}
	write(ans);
	return 0;
}
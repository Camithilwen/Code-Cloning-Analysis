#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30,maxn=2000005;
int i,j,k,n,v[100000005];
int f[maxn],prime[maxn],tot,e[100005];
long long ans[505][505],mx;
map<long long,int> p;
void shai()
{
    tot=0;
    for(int i=2;i<maxn;i++)
    {
        if(!f[i])
            prime[tot++]=i;
        for(int j=0;j<tot&&prime[j]*i<maxn;j++)
        {
            f[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
long long gcd(long long a,long long b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	return a/gcd(a,b)*b;
}
int main()
{
	shai();
	scanf("%d",&n);
	int m=0;
	for(i=1;i<=499;i+=2)
		e[i]=++m;
	for(i=2;i<=499;i+=2)
		e[i]=++m;
	for(i=500;i>=1;--i)
		for(j=500;j>=1;--j)
			if((i+j)&1)
			{
				for(k=prime[e[(i+j)/2]-1];v[k];k+=prime[e[(i+j)/2]-1]);
				ans[i][j]=k;
				v[k]=1;
				p[k]=1;
			}
	for(i=1;i<=500;++i)
		for(j=1;j<=500;++j)
			if(ans[i][j]==0)
			{
				long long s=lcm(lcm(ans[i-1][j],ans[i][j-1]),lcm(ans[i+1][j],ans[i][j+1]));
				ans[i][j]=s+1;
				while(p[ans[i][j]])
					ans[i][j]+=s;
				p[ans[i][j]]=1;
			}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("%lld ",ans[i][j]);
			//mx=max(mx,ans[i][j]);
		}
		printf("\n");
	}
	//cout<<mx<<endl;
}
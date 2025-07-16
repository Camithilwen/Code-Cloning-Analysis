#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define N 101000
#define ll long long
using namespace std;
ll sum,n,a[N],g1[N],g2[N];
ll gcd(ll x,ll y)
{
	if(x==-1||y==-1) return -x*y;
	return y==0?x:gcd(y,x%y);
}
ll dg(ll x)
{
	g1[1]=a[1];g2[n]=a[n];
	g1[0]=g2[n+1]=-1;
	fo(i,2,n) g1[i]=gcd(g1[i-1],a[i]);
	fd(i,n-1,1) g2[i]=gcd(g2[i+1],a[i]);
	ll gd=-1,k=0;
	fo(i,1,n)
	if(a[i]!=1)
	{
		gd=gcd(gcd(a[i]-1,g1[i-1]),g2[i+1]);
		k=i;
		if(((sum-1)/gd)%2==1) break;
		gd=-1;
	}
	if(gd!=-1)
	{
		fo(i,1,n) if(i!=k) a[i]=a[i]/gd;
		a[k]=(a[k]-1)/gd;
		sum=(sum-1)/(ll)gd;
		return 1-dg(x^1);
	}
	return 0;
}
int main()
{
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld",&a[i]),sum+=(ll)a[i];
	if(n%2==0)
	{
		if(sum%2==1) printf("First\n");
		else printf("Second\n");
		return 0;
	}
	if(sum%2==0) return printf("First\n"),0;
	if(dg(1)==1) printf("First\n");
	else printf("Second\n");
}
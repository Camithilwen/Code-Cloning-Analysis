#include<iostream>
using namespace std;
long N,M,mod=998244353;
long F[1<<25],I[1<<25];
long power(long a,long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
long C(long a,long b)
{
	return a<b||a<0||b<0?0:F[a]*I[b]%mod*I[a-b]%mod;
}
long H(long a,long b){return a<0?0:C(a+b-1,b-1);}
long calc(long n,long m,long s)
{
	long ret=0;
	for(int i=0;i<=n&&i<=m;i++)
	{
		if(s-i&1)continue;
		(ret+=C(n,i)*H((s-i)/2,n)%mod)%=mod;
	}
	return ret;
}
main()
{
	cin>>N>>M;
	long T=2*M+N;
	F[0]=1;
	for(long i=1;i<T;i++)F[i]=F[i-1]*i%mod;
	I[T-1]=power(F[T-1],mod-2);
	for(long i=T-1;i--;)I[i]=I[i+1]*(i+1)%mod;
	long ans=0;
	for(int i=0;i<=N&&i<=M;i++)
	{
		if((3*M-i)%2==1)continue;
		(ans+=C(N,i)*H((3*M-i)/2,N)%mod)%=mod;
	}
	long ret=0;
	for(int i=0;i<=N&&i<=M;i++)
	{
		if((M-i)%2==1)continue;
		(ret+=C(N,i)*H((M-i)/2,N)%mod)%=mod;
	}
	for(int i=0;i<=N-1&&i<=M;i++)
	{
		if((M-i)%2==1)continue;
		(ret+=mod-C(N-1,i)*H((M-i)/2,N-1)%mod)%=mod;
	}
	cout<<(calc(N,M,3*M)-calc(N,M,M)*N%mod+calc(N-1,M,M)*N%mod+mod)%mod<<endl;
}

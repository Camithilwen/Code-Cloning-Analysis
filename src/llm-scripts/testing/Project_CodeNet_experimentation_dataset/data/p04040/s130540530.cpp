#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define in read()
#define re register
#define fur(i,a,b) for(re int i=a;i<=b;++i)
#define fdr(i,a,b) for(re int i=a;i>=b;--i)
#define cl(a,b) memset(a,b,sizeof(a))
#define jinitaimei signed
#define int long long
inline int read()
{
	int x=0;
	char ch=getchar();
	for(;!isalnum(ch);ch=getchar());
	for(;isalnum(ch);ch=getchar()) x=x*10+ch-'0';
	return x;
}
const int mod=1e9+7,xx=5e5+1;
inline int power(int b,int k)
{
	int res=1;
	for(;k;k>>=1,b=b*b%mod) if(k&1) res=res*b%mod;
	return res;
}
int jc[xx],ny[xx];
inline int C(int m,int n)
{
	if(!m) return 1;
	return jc[n]*ny[m]%mod*ny[n-m]%mod;
}
jinitaimei main()
{
	jc[0]=1;
	ny[0]=1;
	int H=in,W=in;
	fur(i,1,H+W) jc[i]=jc[i-1]*i%mod,ny[i]=power(jc[i],mod-2);
	int A=in,B=in,ans=0;
	A=H-A+1;
	int up=min(A-1,W-B);
	fur(k,1,up)
	{
		int x=A-k,y=B+k;
		int tmp=C(x-1,x+y-2)*C(H-x,W-x+H-y)%mod;
		(ans+=tmp)%=mod;
	}
	cout<<ans<<endl;
	return 0;
}

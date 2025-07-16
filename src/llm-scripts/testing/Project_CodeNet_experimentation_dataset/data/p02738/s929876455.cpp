#include<bits/stdc++.h>
using namespace std;
#define res register int
#define ll long long
//#define cccgift
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
template<typename T>
inline void read(T &x)
{
    static char ch;bool f=1;
    for(x=0,ch=getchar();!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
    for(;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=getchar());x=f?x:-x;
}
template<typename T>
void print(T x)
{
    if (x<0) x=-x,putchar('-');
    if (x>9) print(x/10);
    putchar(x%10+48);
}
template<typename T>
inline void print(T x,char ap) {print(x);if (ap) putchar(ap);}
template<typename T>
inline void chkmax(T &x,const T &y) {x=x<y?y:x;}
template<typename T>
inline void chkmin(T &x,const T &y) {x=x<y?x:y;}
int f[6001][12001],n,mod;
#define inc(x,y) x+=y,x>=mod?x-=mod:0
int main()
{
	read(n),n*=3,read(mod),f[0][n]=1;
	for(res i=1;i<=n;++i)
	  for(res j=n-i;j<=n+i;++j) {
	  	if(j) inc(f[i][j],f[i-1][j-1]);
	  	if(i>1&&j<2*n) inc(f[i][j],(ll)f[i-2][j+1]*(i-1)%mod);
	  	if(i>2) inc(f[i][j],(ll)f[i-3][j]*(i-1)*(i-2)%mod);
	  }
	int tot=0;
	for(res i=n;i<=2*n;++i) inc(tot,f[n][i]);
	print(tot,'\n');
	return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/ 

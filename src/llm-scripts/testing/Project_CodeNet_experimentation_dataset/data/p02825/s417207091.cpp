// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
const int N=1e3+5;
int n;
char ans[1005][1005];
string s3[3]={
"aab",
"b.b",
"baa",
};
string s4[4]={
"bacc",
"babb",
"ccda",
"aada",
};
string s5[5]={
"accbb",
"ad..a",
"bd..a",
"b.ddc",
"aabbc",
};
string s6[6]={
"oorrzz", 
".a.b.c", 
".a.b.c", 
"d.e.f.", 
"d.e.f.", 
"oorrzz"
};
string s7[7]={
"..bbcca",
"ccdd..a",
".a..d.b",
".a..d.b",
"b....dc",
"b....dc",
"ccbbaa.",
};
int main()
{
	n=read();if(n<3) return puts("-1"),0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans[i][j]=0;
	if(n==3) {for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) sr[++C]=s3[i-1][j-1];sr[++C]='\n';}return ot(),0;}
	if(n==4) {for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) sr[++C]=s4[i-1][j-1];sr[++C]='\n';}return ot(),0;}
	if(n==5) {for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) sr[++C]=s5[i-1][j-1];sr[++C]='\n';}return ot(),0;}
	if(n==6) {for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) sr[++C]=s6[i-1][j-1];sr[++C]='\n';}return ot(),0;}
	if(n==7) {for(int i=1;i<=n;i++){for(int j=1;j<=n;j++) sr[++C]=s7[i-1][j-1];sr[++C]='\n';}return ot(),0;}
	if(n%4==0) for(int i=1;i<=n;i+=4) for(int j=i;j<=i+3;j++) for(int k=i;k<=i+3;k++) ans[j][k]=s4[(j-1)%4][(k-1)%4];
	if(n%4==1)
	{
		for(int i=1;i<=n-5;i+=4) for(int j=i;j<=i+3;j++) for(int k=i;k<=i+3;k++) ans[j][k]=s4[(j-1)%4][(k-1)%4];
		for(int i=n-4;i<=n;i++) for(int j=n-4;j<=n;j++) ans[i][j]=s5[i-n+4][j-n+4];
	}
	if(n%4==2)
	{
		for(int i=1;i<=n-6;i+=4) for(int j=i;j<=i+3;j++) for(int k=i;k<=i+3;k++) ans[j][k]=s4[(j-1)%4][(k-1)%4];
		for(int i=n-5;i<=n;i++) for(int j=n-5;j<=n;j++) ans[i][j]=s6[i-n+5][j-n+5];
	}
	if(n%4==3)
	{
		for(int i=1;i<=n-7;i+=4) for(int j=i;j<=i+3;j++) for(int k=i;k<=i+3;k++) ans[j][k]=s4[(j-1)%4][(k-1)%4];
		for(int i=n-6;i<=n;i++) for(int j=n-6;j<=n;j++) ans[i][j]=s7[i-n+6][j-n+6];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) sr[++C]=(ans[i][j]?ans[i][j]:'.');
		sr[++C]='\n';ot(); 
	}
	return 0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.
/*
----------
aab
b.b
baa
----------
bacc
babb
ccda
aada
----------
accbb
ad..a
bd..a
b.ddc
aabbc
----------
aabb..
b..aa.
ba....
.a..aa
..a..b
..a..b
----------
..bbcca
ccdd..a
.a..d.b
.a..d.b
b....dc
b....dc
ccbbaa.
----------
 
*/
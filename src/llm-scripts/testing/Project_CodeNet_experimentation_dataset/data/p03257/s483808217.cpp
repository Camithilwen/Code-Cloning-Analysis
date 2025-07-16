// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

bool P(int x){for(int i=2;i*i<=x;i++)if(x%i==0)return false;return true;}

int p[1111],p1[1111],p2[1111],tot,n;

LL a[555][555];

int main()
{
	for(int i=2;i<=10000&&tot<1002;i++)if(P(i))p[++tot]=i;
	for(int i=1;i<=501;i++)p1[i*2-1]=p[i];
	for(int i=1;i<=501;i++)p2[i*2-1]=p[i+501];
	for(int i=1;i<=501;i++)for(int j=1;j<=501;j++)
	{
		int k1=i+j-1,k2=i-j+501;
		a[i][j]=1;
		if(k1%2==1)a[i][j]*=p1[k1];else a[i][j]*=p1[k1-1]*p1[k1+1];
		if(k2%2==1)a[i][j]*=p2[k2];else a[i][j]*=p2[k2-1]*p2[k2+1];
		if(k1%2==0)a[i][j]++;
	}
	
	get1(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%lld%c",a[i][j],j==n?'\n':' ');
	return 0;
}
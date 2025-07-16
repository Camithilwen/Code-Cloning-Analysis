#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=10005;
const int MAXM=505;
int pr[MAXN],is[MAXN],plen;
void getpr()
{
	for(int i=2;i<MAXN;i++)
	{
		if(!is[i])pr[++plen]=i;
		for(int j=1;j<=plen&&i*pr[j]<MAXN;j++)
		{
			is[i*pr[j]]=1;
			if(!(i%pr[j]))break;
		}
	}
}
int n,vis[MAXM][MAXM],now;LL a[MAXM][MAXM],b[MAXM][MAXM];
LL gcd(LL a,LL b){return a==0?b:gcd(b%a,a);}
void get1(int x,int y)
{
	if(x>n||y>n)return ;
	vis[x][y]=1;a[x][y]*=pr[now];
	get1(x+1,y+1);
}
void get2(int x,int y)
{
	if(x<1||x>n||y<1||y>n)return ;
	vis[x][y]=1;a[x][y]*=pr[now];
	get2(x+1,y-1);
}
bool in(int x,int y){return x>=1&&x<=n&&y>=1&&y<=n;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
int main()
{
	getpr();	
	n=read();now=0;
	if(n==2)
	{
		printf("4 7\n23 10\n");return 0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(((i+j-1)&1)&&!vis[i][j])
		++now,get1(i,j);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(((i+j-1)&1)&&!vis[i][j])
		++now,get2(i,j);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!((i+j-1)&1))
	{
		if(in(i-1,j))a[i][j]=lcm(a[i][j],a[i-1][j]);
		if(in(i+1,j))a[i][j]=lcm(a[i][j],a[i+1][j]);
		if(in(i,j-1))a[i][j]=lcm(a[i][j],a[i][j-1]);
		if(in(i,j+1))a[i][j]=lcm(a[i][j],a[i][j+1]);
		++a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)pr1(a[i][j]);
		puts("");
	}
	return 0;
}


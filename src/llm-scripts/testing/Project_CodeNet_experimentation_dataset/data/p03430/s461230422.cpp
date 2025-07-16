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
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
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
const int MAXN=305;
int f[MAXN][MAXN][MAXN],n,K;char ch[MAXN];
int main()
{
	scanf("%s",ch+1);n=strlen(ch+1);K=read();
	f[0][n+1][0]=0;int ans=0;
	for(int i=0;i<=n;i++)for(int j=n+1;j>=i;j--)for(int k=0;k<=K;k++)
	{
		int ad=(ch[i]==ch[j]?0:1);
		if(i-1>=0)chkmax(f[i][j][k],f[i-1][j][k]);
		if(j+1<=n+1)chkmax(f[i][j][k],f[i][j+1][k]);
		if(i-1>=0&&j+1<=n+1&&k-ad>=0)chkmax(f[i][j][k],f[i-1][j+1][k-ad]+1);
		if(i<j)chkmax(ans,2*f[i][j][k]);
		else chkmax(ans,2*f[i][j][k]-1);
	}pr2(ans);
	return 0;
}

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
int col[2][2*MAXN][2*MAXN],n,D1,D2;
vector<pii> fac[2];
bool in(int x,int y){return x>=0&&x<2*n&&y>=0&&y<2*n;}
void DFS(int x,int y,int o)
{
	for(auto p:fac[o])for(int u=-1;u<=1;u++)if(u)for(int v=-1;v<=1;v++)if(v)
		if(in(x+u*p.first,y+v*p.second))
		{
			int ux=x+u*p.first,uy=y+v*p.second;
			if(col[o][ux][uy]!=-1)continue;
			col[o][ux][uy]=col[o][x][y]^1;DFS(ux,uy,o);
		}
}
void color(int o)
{
	memset(col[o],-1,sizeof(col[o]));
	for(int i=0;i<2*n;i++)for(int j=0;j<2*n;j++)if(col[o][i][j]==-1)
		col[o][i][j]=0,DFS(i,j,o);
}
int sqr(int x){return x*x;}
int dis(pii u,pii v){return sqr(u.first-v.first)+sqr(u.second-v.second);}
vector<pii> ans[2][2];
int main()
{
	n=read();D1=read();D2=read();
	for(int i=0;i*i<=D1;i++)if(floor(sqrt(D1-i*i))==ceil(sqrt(D1-i*i)))fac[0].emplace_back(mp(i,sqrt(D1-i*i)));
	for(int i=0;i*i<=D2;i++)if(floor(sqrt(D2-i*i))==ceil(sqrt(D2-i*i)))fac[1].emplace_back(mp(i,sqrt(D2-i*i)));
	color(0);color(1);
	for(int i=0;i<2*n;i++)for(int j=0;j<2*n;j++)
		ans[col[0][i][j]][col[1][i][j]].emplace_back(mp(i,j));
	for(int i=0;i<=1;i++)for(int j=0;j<=1;j++)if(SZ(ans[i][j])>=n*n)
	{
//		for(auto p:ans[i][j])for(auto q:ans[i][j])
//			assert(dis(p,q)!=D1&&dis(p,q)!=D2);
		int cnt=0;
		for(auto p:ans[i][j])
		{
			pr1(p.first),pr2(p.second);
			++cnt;if(cnt==n*n)break;
		}
		return 0;
	}
	return 0;
}

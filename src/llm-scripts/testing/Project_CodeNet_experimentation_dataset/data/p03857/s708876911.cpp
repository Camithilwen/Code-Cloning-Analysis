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
const int MAXN=200005;
int n,E1,E2;
struct DSU
{
	int rt[MAXN];
	void init(){for(int i=1;i<=n;i++)rt[i]=i;}
	int findrt(int x){return rt[x]==x?rt[x]:rt[x]=findrt(rt[x]);}
	void merge(int x,int y){rt[findrt(x)]=findrt(y);}
}A,B;
map<int,int> mp[MAXN];
int main()
{
	n=read();E1=read();E2=read();
	A.init();B.init();
	for(int i=1;i<=E1;i++)
	{
		int x=read(),y=read();
		A.merge(x,y);
	}
	for(int i=1;i<=E2;i++)
	{
		int x=read(),y=read();
		B.merge(x,y);
	}
	for(int i=1;i<=n;i++)mp[A.findrt(i)][B.findrt(i)]++;
	for(int i=1;i<=n;i++)pr1(mp[A.findrt(i)][B.findrt(i)]);puts("");
	return 0;
}


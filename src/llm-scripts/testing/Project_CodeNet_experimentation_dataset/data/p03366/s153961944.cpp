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
const int MAXN=100005;
int X[MAXN],n,S;LL P[MAXN];
int main()
{
	n=read();S=read();
	for(int i=1;i<=n;i++)X[i]=read(),P[i]=read();LL ans=0;
	int l=1,r=n,preo=-1;
	while(l<=r&&X[l]<S&&X[r]>S)
	{
		if(P[l]>=P[r])
		{
			P[l]+=P[r];
			if(preo!=2)preo=2,ans+=X[r]-X[l];
			--r;
		}
		else
		{
			P[r]+=P[l];
			if(preo!=1)preo=1,ans+=X[r]-X[l];
			++l;
		}
	}
	if(l<=r)
	{
		if(X[l]>=S)ans+=X[r]-S;
		else ans+=S-X[l];
	}pr2(ans);
	return 0;
}

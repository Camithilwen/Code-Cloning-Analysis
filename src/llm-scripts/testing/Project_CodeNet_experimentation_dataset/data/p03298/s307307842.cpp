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
#define ull unsigned long long
const int MAXN=20;
const int base=233;
char ch[2*MAXN];
int bin[MAXN];
map<ull,int> mp;
int main()
{
//	freopen("a.in","r",stdin);
	bin[1]=1;for(int i=2;i<MAXN;i++)bin[i]=bin[i-1]<<1;
	int n=read();scanf("%s",ch+1);
	for(int i=0;i<bin[n+1];i++)
	{
		ull sum=0;
		for(int j=1;j<=n;j++)if(i&bin[j])
			sum=(sum*base+ch[j]-'a'+1);
		sum=(sum*base+79);
		for(int j=1;j<=n;j++)if(!(i&bin[j]))
			sum=(sum*base+ch[j]-'a'+1);
		++mp[sum];
	}LL ans=0;
	for(int i=0;i<bin[n+1];i++)
	{
		ull sum=0;
		for(int j=1;j<=n;j++)if(i&bin[j])
			sum=(sum*base+ch[2*n-j+1]-'a'+1);
		sum=(sum*base+79);
		for(int j=1;j<=n;j++)if(!(i&bin[j]))
			sum=(sum*base+ch[2*n-j+1]-'a'+1);
		ans+=mp[sum];
	}pr2(ans);
	return 0;
}

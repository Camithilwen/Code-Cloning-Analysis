//BadWaper gg
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define N 220
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int a[N];
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read()<<1;
	for(register int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);int ans=0;
	for(register int i=1;i<=n;i+=2)ans+=a[i];
	printf("%d\n",ans);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#define LL long long
using namespace std;
const int MAX=1e5+3;
LL a[MAX];
LL add[MAX];
inline bool myru(LL x,LL y){return x>y;}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
	//以下规则有先后判定，优先满足靠前的规则 
	//1.如果从大到小排序后a[p]-a[i]>m 则a[i]绝对无法入选
	//2.如果从p到i-1这些数不选时能凑够v个选票，则a[i]可以入选
	//3. ∑j=i-1 To p a[i]+m-a[j] >= (v-n+(i-p))*m ,则a[i]可以入选 
	int i,j;
	LL n,m,v,p;
	n=rin();m=rin();v=rin(),p=rin();
	for(i=1;i<=n;i++)a[i]=rin();sort(a+1,a+n+1,myru);
	
	add[0]=0;for(i=1;i<=n;i++)add[i]=add[i-1]+a[i];
	int ans=p;
	for(i=p+1;i<=n&&a[i]==a[p];i++)ans++;
	for(;i<=n;i++)
	{
		if(a[p]-a[i]>m)continue;
		if(n-(i-p)>=v){ans++;continue;}
		LL sum=a[i]+m;
		sum*=(i-p);
		sum-=add[i-1]-add[p-1];
		if(sum>=m*(v-(n-(i-p))))ans++;
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 100007;
const char *YES = "Yes" , *NO = "No";

inline void failure(){puts(NO);exit(0);}

struct tla
{
#define lb(a) ((a)&(-(a)))
	int t[_];
	void cls(){memset(t,0,sizeof(t));}
	inline void add(int x,int d){while(x)t[x]+=d,x-=lb(x);}
	inline int sum(int x){int d=0;while(x<_)d+=t[x],x+=lb(x);return d;}
#undef lb
}t;

int n,val[_][3],tar[_],ic[2]={0},fc[2]={0};

int main()
{
	n=ty();
	for(int i=0;i<3;i++)for(int j=1;j<=n;j++)val[j][i]=ty();

	for(int i=1;i<=n;i++)
	{
		int loc=(val[i][0]-1)/3+1;
		if((loc-i)&1)failure();
		tar[loc]=i;
		int a=loc*3-2,b=a+1,c=b+1;
		if(val[i][0]==a && val[i][1]==b && val[i][2]==c)continue;
		if(val[i][0]==c && val[i][1]==b && val[i][2]==a)ic[i&1]^=1;
		else failure();
	}

	t.cls();
	for(int i=1,x;i<=n;i+=2)x=tar[i]+t.sum(tar[i])*2,fc[1]^=((x-i)/2)&1,t.add(tar[i],1);
	t.cls();
	for(int i=2,x;i<=n;i+=2)x=tar[i]+t.sum(tar[i])*2,fc[0]^=((x-i)/2)&1,t.add(tar[i],1);

	puts((ic[1]==fc[0] && ic[0]==fc[1])?YES:NO);

	return 0;
}

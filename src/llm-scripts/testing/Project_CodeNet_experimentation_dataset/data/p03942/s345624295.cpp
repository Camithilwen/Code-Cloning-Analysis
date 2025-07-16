#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define SZ 1234567
int n,h_[SZ+SZ],*h=h_,dt=0; char s[SZ],t[SZ];
int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	if(strcmp(s+1,t+1)==0)
	{
		puts("0");
		return 0;
	}
	int cr=n,cl=n+1,ans=0;
	for(int i=n;i>=1;--i)
	{
		if(t[i-1]==t[i]) continue;
		int x=min(cl-1,i);
		while(x&&s[x]!=t[i]) --x;
		if(!x)
		{
			puts("-1");
			return 0;
		}
		int ir=i;
		while(t[ir+1]==t[i]) ++ir;
		while(cl>x)
			h[--cl]=-dt;
		while(cr>=ir)
			ans=max(ans,h[cr--]+dt);
		++h; ++dt;
	}
	while(cl>1)
		h[--cl]=-dt;
	while(cr>=1)
		ans=max(ans,h[cr--]+dt);
	printf("%d\n",ans);
}
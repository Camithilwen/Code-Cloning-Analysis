#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#define N 1100000
using namespace std;
char s[N],t[N];
int p[N],head,tail,n,f[N],ans;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	bool bo=1;
	for(int i=1;i<=n;i++) if(s[i]!=t[i]) {bo=0;break;}
	if(bo) {printf("0\n");return 0;}
	int j=n;
	for(int i=n;i>=1;i--)
	{
		j=min(j,i);
		while(j && s[j]!=t[i]) j--;
		if(j==0) {printf("-1\n");return 0;}
		f[i]=j;
	}
	head=1;tail=0;
	for(int i=n;i>=1;i--)
	{
		while(head<=tail && p[head]-(tail-head)>i) head++;
		if(f[i]!=f[i+1]) p[++tail]=f[i];
		ans=max(ans,tail-head+1);
	}
	printf("%d\n",ans);
	return 0;
}
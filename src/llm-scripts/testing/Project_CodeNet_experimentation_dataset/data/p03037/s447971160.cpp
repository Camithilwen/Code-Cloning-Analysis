#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
int main()
{
	int x,y,l=0,r=maxn;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		l=max(x,l),r=min(y,r);
	}
	if(l>r)printf("0");
	else printf("%d\n",r-l+1);
	return 0;
}
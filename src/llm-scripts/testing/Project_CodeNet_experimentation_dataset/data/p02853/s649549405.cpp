#include<iostream>
#include<cstdio>
using namespace std;
int x,y;
int main()
{
	scanf("%d%d",&x,&y);
	int ans=0;
	if(x==1) ans+=30;
	else if(x==2) ans+=20;
	else if(x==3) ans+=10;
	if(y==1) ans+=30;
	else if(y==2) ans+=20;
	else if(y==3) ans+=10;
	if(x==1&&y==1) ans+=40;
	ans*=10000;
	printf("%d",ans);
	return 0;
}
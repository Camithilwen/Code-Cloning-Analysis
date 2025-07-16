#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	int ans;
	if(n<10)
	{
		ans=r+(10-n)*100;
	}
	else ans=r;
	printf("%d",ans);
}
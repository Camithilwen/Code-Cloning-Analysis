#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int m,n;
	int mp[100005];	
	scanf("%d %d",&m,&n);
	memset(mp,0,sizeof(mp));
	int t=n;
	while(t--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
	for(int i=l;i<=r;i++)
	{
		mp[i]++;
	}
    }
    int sum=0;
    for(int i=1;i<=m;i++)
    {
    	if(mp[i]==n)
    	sum++;
	}
	printf("%d\n",sum);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int s[501],q[1001][5];
int main()
{
	int i,j,n,m,a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0)break;
		cin>>n;
		for(i=1;i<=500;i++)s[i]=2;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=4;j++)
			{
				cin>>q[i][j];
			}
			if(q[i][4]==1)
			{
				s[q[i][1]]=1;
				s[q[i][2]]=1;
				s[q[i][3]]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(s[q[i][1]]==1&&s[q[i][2]]==1&&q[i][4]==0)s[q[i][3]]=0;
			else if(s[q[i][1]]==1&&s[q[i][3]]==1&&q[i][4]==0)s[q[i][2]]=0;
			else if(s[q[i][3]]==1&&s[q[i][2]]==1&&q[i][4]==0)s[q[i][1]]=0;
		}
		for(i=1;i<=a+b+c;i++)
		{
			cout<<s[i]<<endl;
		}
	}
	return 0;
}
#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,i,a,b,c,f[1000],sum_max=-999999999,sum;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(a=0;a<=k;a++)
	{
		for(b=0;b<=k;b++)
		{
				for(c=0;c<=k;c++)
				{
					priority_queue<int>q;
					if(a+b+c<=k&&a+b>=c&&a+b<=n)
					{
						for(i=0;i<a;i++)
						{
					       q.push(f[i]);
						}
						for(i=0;i<b;i++)
						{
					       q.push(f[n-i-1]);
						}
						int sum=0;
						for(i=0;i<a+b-c;i++)
						{
							sum=sum+q.top();
							q.pop();
						}
						sum_max=max(sum_max,sum);
					}
				}
			
		}
	}
	printf("%d",sum_max);
	return 0;	
}
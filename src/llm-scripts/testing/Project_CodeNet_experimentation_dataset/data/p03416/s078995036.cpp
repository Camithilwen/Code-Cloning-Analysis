#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,count=0,i,temp,sum;
	cin>>a>>b;

	for(i=a;i<=b;i++)
	{
		sum=0;
		temp = i;
		while(temp)
		{
			sum*=10;
			sum+=(temp%10);
			temp/=10;
		}

		if(sum==i)
			count++;
	}

	cout<<count<<endl;

	return 0;
}

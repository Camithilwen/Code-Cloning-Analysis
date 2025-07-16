#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,A,B;
	scanf("%d %d %d %d",&n,&m,&A,&B);
	for(int i=0;i<B;i++)
	{
		for(int j=0;j<m;j++) printf("%c",j<A?'0':'1');
		puts("");
		for(int j=0;j<m;j++) printf("%c",j<A?'1':'0');
		puts("");
	}
	for(int i=0;i<n-2*B;i++)
	{
		for(int j=0;j<m;j++) printf("%c",j<A?'0':'1');
		puts("");
	}
}
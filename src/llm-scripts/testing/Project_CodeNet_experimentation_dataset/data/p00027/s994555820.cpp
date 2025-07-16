#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <cmath>
#define mp make_pair
#define pii pair<int,int> 
#define ff first
#define ss second

using namespace std;

int month[20]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string days[10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int a,b,c,d;
int main()
{
	while(1)
	{
		scanf("%d %d",&a,&b);
		c=0;
		if(a==0&&b==0)
		{
			break;
		}
		for(int i=1;i<a;i++)
		{
			c+=month[i];
		}
		c+=b+2;
		d=c%7;
		//printf("%d\n",c);
		cout<<days[d]<<endl;
	}
	return 0;
}
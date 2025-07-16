#include <iostream>
using namespace std;
int main(void)
{
	int a,b,c[101]={0},d,e=0,f=0,g,h,i;
	for (a=0;a<4;a++)
	{
		cin>>b;
		c[b]=1;
	}
	for (a=100;a>0;a--)
	{
		if (c[a]==1&&e!=3)
		{
			f=f+a;
			e++;
		}
	}
	cin>>d>>e;
	if (d>=e)
	{
		g=d+f;
	}
	else if (d<=e)
	{
		g=e+f;
	}
	cout<<g<<endl;
	return 0;
}
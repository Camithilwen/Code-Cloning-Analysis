#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	double x1,x2,y1,y2,x,y,z;
	cin>>x1>>y1>>x2>>y2;
	x=x2-x1;
	y=y2-y1;
	x *=x;
	y *=y;
	z=sqrt(x+y);
	printf("%lf\n",z);
	return 0;
}
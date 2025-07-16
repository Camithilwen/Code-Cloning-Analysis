#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double x1,y1,x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	printf("%4lf\n",sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
	return 0;
	
}
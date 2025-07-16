#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstdio>
using namespace std;

int main()
{
	double  x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double X = max(x1, x2) - min(x1, x2);
	double Y = max(y1, y2) - min(y1, y2);

	printf("%.8lf\n", sqrt(X*X + Y*Y));


	return 0;

}
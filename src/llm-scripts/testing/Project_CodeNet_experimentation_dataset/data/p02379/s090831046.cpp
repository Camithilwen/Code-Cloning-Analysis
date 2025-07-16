#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main(){
	double x1, y1, x2, y2;
	double ans;
	
	cin >> x1 >> y1 >> x2 >> y2;
	ans = pow((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1), 0.5);
	
	printf("%.8f\n", ans);
	
	return 0;
} 
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
	double x1, y1, x2, y2, x, y, ans;
	cin >> x1 >> y1 >> x2 >> y2;
	x = x1 - x2;
	y = y1 - y2;
	ans = sqrt(x*x + y*y);
	printf("%f", ans);
	return 0;
}
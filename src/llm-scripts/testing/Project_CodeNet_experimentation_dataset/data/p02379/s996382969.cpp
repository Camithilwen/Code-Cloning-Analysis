#include <iostream>
#include <string>
#include <stddef.h>
#include <stack>
#include <queue>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {
	double x1, x2, y1, y2;
	double d;
	cin >> x1 >> y1 >> x2 >> y2;
	d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	printf("%.8f\n", d);
	
}
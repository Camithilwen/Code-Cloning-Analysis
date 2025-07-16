#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>
#define INF 2147483647

using namespace std;



int main()
{
	double x1, y1, x2, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	cout << fixed << setprecision(8) << sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0))  <<  endl;

	return (0);
}
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main () {
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << setprecision(20) <<sqrt((a-c)*(a-c)+(b-d)*(b-d));
	return 0;
}
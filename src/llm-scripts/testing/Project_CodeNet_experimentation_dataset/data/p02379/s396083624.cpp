#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double x1, y1, x2, y2;
	cin >> setprecision(10) >> x1;
	cin >> setprecision(10) >> y1; 
	cin >> setprecision(10) >> x2;
	cin >> setprecision(10) >> y2;
	cout << setprecision(10) << sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) << endl;
	return 0;
}
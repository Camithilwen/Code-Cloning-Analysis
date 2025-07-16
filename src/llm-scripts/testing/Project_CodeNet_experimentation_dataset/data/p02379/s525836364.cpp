
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){

	double x1, x2, y1, y2;

	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 == x2){
		cout << setprecision(12) << fabs(y1 - y2) << endl;
	}
	else if (y1 == y2){
		cout << setprecision(12) << fabs(x1 - x2) << endl;
	}
	else {
		cout << setprecision(12) << sqrt(pow(fabs(x1 - x2), 2) + pow(fabs(y1 - y2), 2)) << endl;
	}

	return 0;
}

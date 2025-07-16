#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	double x, y, x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x = fabs(x2 - x1);
	y = fabs(y2 - y1);
	if( x == 0 ) {
		cout << fixed << setprecision(5) << y << "\n";
		return 0;
	} else if( y == 0 ) {
		cout << fixed << setprecision(5) << x << "\n";
		return 0;
	}

	int c = 0;

	double v = x*x + y*y,
	       d = max(x, y),
		   eps = 0.00001;
	do
	{
		d = (d + v / d ) / 2.0L;
		++c;
	}
	while( c < 5 );

	cout << fixed << setprecision(5) << d << "\n";

	return 0;
}
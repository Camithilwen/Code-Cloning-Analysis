#include <iostream>
#include <math.h>

using namespace std;


class point{
public:
	double x, y;
	int set();
};

int point::set()
{
	cin >> x >> y;
	return 0;
}

int main()
{
	point P1, P2;
	P1.set();
	P2.set();

	cout << fixed << sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y)) << endl;

	return 0;
}
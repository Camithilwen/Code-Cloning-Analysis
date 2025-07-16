#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char const* argv[])
{
	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	double x = std::abs( x1 - x2 );
	double y = std::abs( y1 - y2 );

	std::cout << std::setprecision(20) << std::sqrt( x * x + y * y ) << std::endl;

	return 0;
}
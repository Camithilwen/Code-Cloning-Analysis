#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>

int main(void) {

	//long double x = 0.1234567890;
	//std::cout << x << std::endl;

	//test??¨
	//std::ifstream in("test.txt");
	//std::cin.rdbuf(in.rdbuf());

	double x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	long double ans = sqrtl(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
	
	std::cout << std::fixed << std::setprecision(8) << ans << std::endl;
}
#include <iostream>
using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	double ans = (double)2 * (n-d) / n / n * (m-1);
	if (d == 0) ans /= 2;
	printf("%.15lf\n", ans);
	return 0;
}

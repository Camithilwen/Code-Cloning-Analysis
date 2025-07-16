#include <iostream>

using namespace std;

int main()
{
	double n, m;
	int d;
	cin >> n >> m >> d;

	double ans = 1.0;
	if (d == 0) {
		ans *= m - 1;
		ans /= n;
	}else{
		ans = 2.0 * (n - d);
		ans *= m - 1;
		ans /= n * n;
	}
	printf("%.10f\n", ans);

	return 0;
}
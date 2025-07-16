#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
	double x1, y1, x2, y2, num, ans = 0, dou = 1, xx;
	cin >> x1 >> y1 >> x2 >> y2;
	num = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	while (dou < num) {
		dou *= 10;
	}
	xx = dou;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < i; j++) {
			dou *= 0.1;
		}
		if (dou < 0.000001)break;
		for (int j = 0; j < 10; j++) {
			ans += dou;
			//cout << ans << " " << j << " " << dou << endl;
			if (ans*ans > num) {
				ans -= dou;
				break;
			}
		}
		dou = xx;
	}
	printf("%f\n", ans);
	//cout << ans;

	return 0;
}
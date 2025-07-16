#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265359
using namespace std;

int main() {
	int n;
	cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		double l1 = 0, r1 = PI, l2 = - PI, r2 = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				double th = atan2(y[j] - y[i], x[j] - x[i]);
				//cout << th << " ";
				if (th < -0.5 * PI && x[i] != x[j]) {
					l2 = max(l2, th + PI * 0.5);
					r1 = min(r1, th + PI * 1.5);
				} else if (th < 0.5 * PI || x[i] == x[j]) {
					l1 = max(l1, th + PI * 0.5);
					r2 = min(r2, th - PI * 0.5);
				} else {
					l2 = max(l2, th - PI * 1.5);
					r1 = min(r1, th - PI * 0.5);
				}
				//cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
			}
		}
		printf("%.10lf\n", max(0., (r1 - l1) / 2 / PI) + max(0., (r2 - l2) / 2 / PI));
	}
    return 0;
}
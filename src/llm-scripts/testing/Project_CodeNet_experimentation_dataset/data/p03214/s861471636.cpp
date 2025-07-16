#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	int n, a[100],ans;
	float sum = 0,min=101.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	for (int i = 0; i < n; i++) {
		if (fabs(a[i] - sum) == min)continue;
		if (fabs(a[i] - sum) < min){
          	min = fabs(a[i] - sum);
			ans = i;

        }
	}
	cout << ans;
}
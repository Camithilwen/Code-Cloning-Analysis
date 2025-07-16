#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a = 0, b = 0, a_sum[11] = { 0 }, b_sum[11] = { 0 };
	for (int i = 0; i < 10; i++) {
		cin >> a;
		a_sum[i] = a;
	}
	for (int j = 0; j < 10; j++) {
		cin >> a;
		b_sum[j] = a;
	}
	a = 0;
	sort(a_sum, a_sum + 10);
	sort(b_sum, b_sum + 10);
	/*for (int i = 0; i < 10; i++) {
		cout << a_sum[i] << "," << b_sum[i] << endl;
	}*/
	for (int i = 9; i >6; i--) {
		a += a_sum[i];
		b += b_sum[i];
	}
	cout << a << " " << b << endl;
}
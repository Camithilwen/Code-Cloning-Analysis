#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int w[10];
	int k[10];
	for (int i = 0; i < 10; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> k[i];
	}
	sort(w, w + 10);
	sort(k, k + 10);
	int wSum = 0, kSum = 0;
	for (int i = 9; i > 6; i--) {
		wSum += w[i];
	}
	for (int i = 9; i > 6; i--) {
		kSum += k[i];
	}
	cout << wSum << " " << kSum << endl;
	return 0;
}
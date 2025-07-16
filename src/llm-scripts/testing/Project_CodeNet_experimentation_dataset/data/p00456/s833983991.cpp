#include <iostream>

int main() {
	int k[10] = {}, w[10] = {};
	int swap;
	for (int i = 0; i < 10; i++) {
		std::cin >> w[i];
	}
	for (int j = 0; j < 10; j++) {
		std::cin >> k[j];
	}

	for (int n = 1; n < 10; n++) {
		for (int m = 0; m < 10; m++) {
			if (w[n] > w[m]) {
				swap = w[m];
				w[m] = w[n];
				w[n] = swap;
			}
		}
	}
	for (int n = 1; n < 10; n++) {
		for (int m = 0; m < 10; m++) {
			if (k[n] > k[m]) {
				swap = k[m];
				k[m] = k[n];
				k[n] = swap;
			}
		}
	}

	std::cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << std::endl;
	
	return 0;
}
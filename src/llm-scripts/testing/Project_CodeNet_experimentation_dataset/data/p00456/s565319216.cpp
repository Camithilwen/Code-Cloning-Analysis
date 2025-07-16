#include <iostream>
int main(){
	int w[10], k[10];
	for (int i = 0; i < 10; i++) {
		std::cin >> w[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (w[j] < w[j + 1]) {
				int c = w[j];
				w[j] = w[j + 1];
				w[j + 1] = c;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		std::cin >> k[i];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (k[j] < k[j + 1]) {
				int c = k[j];
				k[j] = k[j + 1];
				k[j + 1] = c;
			}
		}
	}
	std::cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << std::endl;
}
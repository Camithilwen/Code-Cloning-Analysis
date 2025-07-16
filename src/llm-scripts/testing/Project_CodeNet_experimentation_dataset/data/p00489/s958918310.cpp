#include<iostream>
#include<algorithm>
#include<vector>
int main() {
	int N;
	std::cin >> N;
	std::vector<int>sum(N), sort(N);
	for (int i = 0; i < (N - 1)*N / 2; i += 1) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		if (c > d) {
			sum[a - 1] += 3;
		}
		else if (d > c) {
			sum[b - 1] += 3;
		}
		else {
			sum[a - 1] += 1;
			sum[b - 1] += 1;
		}
	}
	for (int i = 0; i < N; i += 1)
		sort[i] = sum[i];
	std::sort(sort.begin(), sort.end());
	for (int i = 0; i < N; i += 1)
		for (int j = N-1; j >= 0; j -= 1) {
			if (sum[i] == sort[j]) {
				std::cout << N-j << std::endl;
				break;
			}
		}
	return 0;
}
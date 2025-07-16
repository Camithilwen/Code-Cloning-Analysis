#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int count = 0;
	int result = 200;

	for (int i = 0; i < N; i++) {
		cin >> A.at(i);

		while (true) {
			if (A.at(i) % 2 != 0 || A.at(i) == 0) {
				break;
			}

			else if (A.at(i) % 2 == 0) {
				A.at(i) = A.at(i) / 2;
				count++;
			}
		}

		result = min(result, count);
		count = 0;
	}

	cout << result << endl;
}
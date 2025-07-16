#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	int cx = M + 1, cnts = 0;
	for (int i = M; i >= 1; i--) {
		if (N % 2 == 0 && (cx - i) * 2 >= N && cnts == 0) { cx++; cnts = 1; }
		cout << i << " " << cx << endl;
		cx++;
	}
	return 0;
}
#include <iostream>
using namespace std;
char judge(int, int, int);

int main() {
	int n, pm, pe, pj;
	while (true) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0;i < n;i++) {
			cin >> pm >> pe >> pj;
			cout << judge(pm, pe, pj) << endl;
		}
	}
}

char judge(int math, int eng, int jap) {
	float twoave = (math + eng) / 2;
	float ave = (math + eng + jap) / 3;
	if (math == 100 || eng == 100 || jap == 100) {
		return 'A';
	} else if (twoave >= 90) {
		return 'A';
	} else if (ave >= 80) {
		return 'A';
	} else if (ave >= 70) {
		return 'B';
	} else if (ave >= 50 && (math >= 80 || eng >= 80)) {
		return 'B';
	} else {
		return 'C';
	}
}
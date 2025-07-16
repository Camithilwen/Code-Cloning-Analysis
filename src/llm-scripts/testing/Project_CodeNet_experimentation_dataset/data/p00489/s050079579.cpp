#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int p[100] = {};

	for (int i = 0;i < n*(n - 1) / 2;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c > d)p[a - 1] += 3;
		else if (c < d)p[b - 1] += 3;
		else {
			p[a - 1]++;
			p[b - 1]++;
		}
	}
	int ans[100];
	for (int i = 0;i < n;i++) {
		int a = 0;
		for (int j = 0;j < n;j++) {
			if (p[i] < p[j])a++;
		}
		ans[i] = a + 1;
	}
	for (int i = 0;i < n;i++)cout << ans[i] << endl;
	return 0;
}
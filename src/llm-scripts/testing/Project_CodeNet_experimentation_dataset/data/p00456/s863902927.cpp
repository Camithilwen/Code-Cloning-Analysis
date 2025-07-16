#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int sum[2] = {0}, num[10] = { 0 }, i, j;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 10; i++) {
			cin >> num[i];
		}
		sort(num, num + 10);
		sum[j] = num[7] + num[8] + num[9];
	}
	cout << sum[0] << " " << sum[1] << endl;
	return 0;
}
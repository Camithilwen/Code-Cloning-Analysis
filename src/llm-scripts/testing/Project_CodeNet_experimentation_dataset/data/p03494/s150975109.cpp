#include<iostream>

using namespace std;

int main(void) {
	int N;
	int a[200];
	int count = 0;
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	while (true) {
		bool odd_flag = false;
		//奇数かどうかの判定
		for (int j = 0; j < N; j++) {
			if (a[j] % 2 != 0) {
				odd_flag = true;
			}
		}
		//flagがtrueならwhile文を抜ける
		if (odd_flag) break;
		//実際に2で÷処理をする
		for (int k = 0; k < N; k++) {
			a[k] /= 2;
		}
		count++;
	}
	printf("%d", count);
}

#include <stdio.h>
//#include <math.h>
using namespace std;

int log10(int n) {
	int keta = 0;
	do{
		n /= 10;
		keta++;
	} while (n > 0);
	return keta;
}

int main() {
	const int MAX_N = 20;
	int N;
	int table[MAX_N][MAX_N];

	while (1) {
		for (int i = 0;i < MAX_N;i++) {
			for (int j = 0;j < MAX_N;j++) {
				table[i][j] = 0;
			}
		}
		scanf("%d", &N);
		if (!N)break;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				scanf("%d", &table[i][j]);
			}
		}

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				table[i][N] += table[i][j];
				table[N][j] += table[i][j];
				table[N][N] += table[i][j];
			}
		}

		for (int i = 0;i <= N;i++) {
			for (int j = 0;j <= N;j++) {
				for (int k = 0;k < 5-log10(table[i][j]);k++) {
					printf(" ");
				}
				printf("%d", table[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
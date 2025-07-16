#include<stdio.h>



int GCD(int a, int b) {
	int A, B, buff;
	// A >= B
	if (b > a) {
		A = b; B = a;
	}
	else { A = a; B = b; }
	while (A%B) {
		buff = B;
		B = A % B;
		A = buff;
	}
	return B;
}

int main() {
	int N, a, b, c;
	int G;
	int GC[1000000];
	scanf("%d", &N);
	if (!(N - 2)) {
		scanf("%d %d", &a, &b);
		G = GCD(a, b);
		for (int i = 1; i <= G; i++) {
			if (a%i == 0 && b%i == 0) {
				GC[i] = i;
			}
			else GC[i] = -i;
		}
		for (int j = 1; j <= G; j++) {
			if (GC[j] < 0)continue;
			printf("%d\n", GC[j]);
		}
	}
	else {
		scanf("%d %d %d", &a, &b, &c);
		G = GCD(c, GCD(a, b));
		for (int i = 1; i <= G; i++) {
			if (a%i == 0 && b%i == 0 && c%i == 0) {
				GC[i] = i;
			}
			else GC[i] = -i;
		}
		for (int j = 1; j <= G; j++) {
			if (GC[j] < 0)continue;
			printf("%d\n", GC[j]);
		}
	}

	return 0;
}

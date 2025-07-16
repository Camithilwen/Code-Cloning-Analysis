#include <stdio.h>
long long n, a, b;
int main() {
	scanf("%lld", &n);
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			a = i;
			b = n / i;
		}
	}
	a = 0;
	while (b) {
		b /= 10;
		a++;
	}
	printf("%lld\n", a);
}
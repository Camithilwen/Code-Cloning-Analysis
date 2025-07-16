#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	if(a < 10) {
		a = 100 * (10 - a);
		b = b + a;
		printf("%d", b);
	} else {
		printf("%d", b);
	}
	
	return 0;
}
#include <stdio.h>


int main () {
	int a,b;
	int tampung = 1;
	scanf("%d", &a);
	scanf("%d", &b);
	
	for ( int i = 0 ; i < a; i++) {
		if (tampung <= b) {
			tampung *= 2;
		} else {
			tampung += b;
		}
	}
	printf ("%d\n", tampung);
	return 0;
}
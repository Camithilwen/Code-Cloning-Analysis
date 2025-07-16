#include <stdio.h>
int main () {
	int n, r;
	scanf("%d %d", &n, &r) ;
	if (n<10) {
		printf("%d\n", r+(1000-100*n)) ;
	}
	else if (n>=10) {
		printf("%d\n", r) ;
	}
}
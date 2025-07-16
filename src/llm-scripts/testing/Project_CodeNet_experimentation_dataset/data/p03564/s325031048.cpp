#include <stdio.h>

int main() {
	int start = 1, n, t, x = 0;
	scanf("%d", &n);
	scanf("%d", &t);
	
	for(int i = 0; i < (n-x); i++) {
		while(start < t) {
			if(x >= n) {
				break;
			}
			start *= 2;
			x++;
		}
		if(x >= n) {
			break;
		}
		start += t;
	}
	printf("%d", start);
	
	return 0;
}
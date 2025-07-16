#include <stdio.h>

char buf[100];
int l[10], v[2];

int main() {
	while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", l, l + 1, l + 2, l + 3, l + 4, l + 5, l + 6, l + 7, l + 8, l + 9, v, v + 1) != -1) {
		int total = 0;
		int i;
		
		for (i = 0; i < 10; i++) total += l[i];
		
		int now = 0;
		for (i = 0; i < 10; i++) {
			now += l[i];
			if (now * v[1] >= (total - now) * v[0]) {
				break;
			}
		}
		printf("%d\n", i + 1);
	}
	return 0;
}
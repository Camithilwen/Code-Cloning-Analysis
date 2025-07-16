#include <stdio.h>

int
main(void)
{
	char line[80];
	int x;

	if (gets(line)) {
		if (sscanf(line, "%d", &x) == 1) {
			printf("%d\n", x*x*x);
		}
	}

	return 0;
}
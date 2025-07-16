#include <stdio.h>

int
main(void)
{
	char line[80];

	int l[10], v[2];

	while (true) {
		if (fgets(line, sizeof line, stdin) == NULL) {
			break;
		}
		if (sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
				   &(l[0]), &(l[1]), &(l[2]), &(l[3]), &(l[4]), &(l[5]),
				   &(l[6]), &(l[7]), &(l[8]), &(l[9]),
				   &(v[0]), &(v[1])) != 12) {
			break;
		}

		int total = 0;
		for (int k : l) {
			total += k;
		}
		
		double h = (double)(v[0]) / (v[0] + v[1]);
		
		double p = total * h;
		
		for (int i = 0; i < 10; i++) {
			p -= l[i];
			if (p <= 0) {
				printf("%d\n", i+1);
				break;
			}
		}
	}

	return 0;
}
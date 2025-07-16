#include <stdio.h>
#include <stdbool.h>

char dividing(int pm, int pe, int pj);

int main(void)
{
	int ninnzuu;
	int point[3];
	while(true) {
		scanf("%d", &ninnzuu);
		if(ninnzuu == 0) {
			break;
		}
		for(int i = 0; i < ninnzuu; i++) {
			scanf("%d %d %d", &point[0], &point[1], &point[2]);
			printf("%c\n", dividing(point[0], point[1], point[2]));
		}
	}
	return 0;
}

char dividing(int pm, int pe, int pj)
{
	if(pm == 100 || pe == 100 || pj == 100) {
		return 'A';
	}else 	if(pm + pe >= 180) {
		return 'A';
	}else 	if(pm + pe + pj >= 240) {
		return 'A';
	}else  	if(pm + pe + pj >= 210) {
		return 'B';
	}else  	if(pm + pe + pj >= 150 && (pm >= 80 || pe >= 80)) {
		return 'B';
	}else{
		return 'C';
	}
}
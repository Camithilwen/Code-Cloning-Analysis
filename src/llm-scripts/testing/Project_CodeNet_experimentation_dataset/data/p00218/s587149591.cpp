#include <stdio.h>

#define MYSCAN scanf

int main(void){
	int n, pm, pe, pj;

	while (true){

		MYSCAN("%d", &n);
		if (n == 0){ break; }
		for (int i = 0; i < n; i++){
			MYSCAN("%d%d%d", &pm, &pe, &pj);
			if (pm == 100 || pe == 100 || pj == 100){
				printf("A\n");
			}
			else if (pm + pe >= 180){
				printf("A\n");
			}
			else if (pm + pe + pj >= 240){
				printf("A\n");
			}
			else if (pm + pe + pj >= 210){
				printf("B\n");
			}
			else if (pm + pe + pj >= 150 && (pm >= 80 || pe >= 80)){
				printf("B\n");
			}
			else{
				printf("C\n");
			}	
		}
	}	
	return 0;
}
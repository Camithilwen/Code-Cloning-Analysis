#include <stdio.h>

int main(void){
	int n;
	int pm, pe, pj;
	double avr;
	
	while (scanf("%d", &n), n){
		for (int i=0; i<n; i++){
			scanf("%d %d %d", &pm, &pe, &pj);
			avr = (pm+pe+pj)/3.;
			if (pm==100 || pe==100 || pj==100){
				puts("A");
			} else if (pm+pe >= 180){
				puts("A");
			} else if (avr>=80){
				puts("A");
			} else if (avr >= 70){
				puts("B");
			} else if (avr >= 50 && (pm>=80 || pe >= 80)){
				puts("B");
			} else {
				puts("C");
			}
		}
	}
	return 0;
}
	
	
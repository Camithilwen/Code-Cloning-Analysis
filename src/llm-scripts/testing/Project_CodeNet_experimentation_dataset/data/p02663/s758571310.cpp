#include <stdio.h>

int main(){
	int h1, m1, h2, m2, k;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	if(h1>h2){
		h1-=24;
	}
	if(h2 == 0 && h1 != 0){
		h2 = 24;
	}
	if(m2<m1){
		m2 += 60;
		h2--;
	}
	int mins = (h2-h1)*60 + (m2-m1);
	mins-=k;
	
	printf("%d\n", mins);
	
	return 0;
}
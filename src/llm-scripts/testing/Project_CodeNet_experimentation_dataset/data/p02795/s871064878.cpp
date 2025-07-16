#include <stdio.h>

int main() {
	int h,w,n;
	scanf("%d", &h);
	scanf("%d", &w);
	scanf("%d", &n);
	int ctr = 0;
	int total = 0;
	while (n > total){
		if(w >= h){
			total += w;
			ctr++;
		}else if(h > w){
			total += h;
			ctr++;
		}
	}
	printf("%d\n",ctr);
	
	return 0;
}

#include <stdio.h>

int main(){
	int a, b, c, d;
	int K;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &K);
	int diff1 = c - a;
	int diff2 = d - b;
	int min = (diff1 * 60) + diff2;
	printf("%d", min - K);
	
	
	
	return 0;
}
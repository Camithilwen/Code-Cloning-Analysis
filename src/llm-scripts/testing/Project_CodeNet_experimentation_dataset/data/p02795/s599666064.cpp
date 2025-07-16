#include<stdio.h>

int main() {
	int row, col, n;
	scanf("%d %d %d", &row, &col, &n);
	
	int bucket;
	if (row >= col){
		bucket = row;
	} else	{
		bucket = col;
	}
	
	int i = 0, j;
	int count = 0;
	
	while (i < n){
		count++;
		i += bucket;
	}
	
	printf("%d\n", count);
	
	return 0;
}


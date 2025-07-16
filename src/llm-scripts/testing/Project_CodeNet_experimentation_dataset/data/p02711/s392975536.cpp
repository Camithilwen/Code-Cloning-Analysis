#include <stdio.h>

int main(){
	int n;
	int n1, n2, n3;
	scanf("%d", &n);
	
	n1 = n/100;
	n2 = (n%100)/10;
	n3 = n%10;
	
	if (n1 == 7 || n2 == 7 || n3 == 7){
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;
}
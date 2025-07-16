#include <stdio.h>

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	int flag = 0;
	char str [a+b+1];
	scanf("%s", str);
	int atr = 0;
	
	for ( int i = 0 ; i < a+b+1 ; i++) {
		if (str[i] == '-' && i == a ) {
			flag = 1;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			++atr;
		}
	}
	int total = a+b; 
	if (flag == 1 && atr == total) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
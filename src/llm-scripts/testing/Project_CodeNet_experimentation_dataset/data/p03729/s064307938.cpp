#include <stdio.h>

int main () {
	char a[12];
	char b[12];
	char c[12];
	int lenA = 0, lenB = 0;
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	
	for(int i = 0; a[i] != '\0'; i++) {
		lenA++;
	}
	for(int i = 0; b[i] != '\0'; i++) {
		lenB++;
	}
	
	if (a[lenA-1] == b [0] && b[lenB-1] == c[0]) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	
	
	
	
	
	return 0;
}
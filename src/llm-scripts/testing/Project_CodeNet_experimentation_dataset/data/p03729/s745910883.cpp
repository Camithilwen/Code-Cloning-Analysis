#include <stdio.h>
#include <string.h>

int main() {
	char a[11], b[11], c[11];

	scanf("%s %s %s", a, b, c);
	int l1 = strlen(a);
	int l2 = strlen(b);
	
	if(a[l1 - 1] == b[0] && b[l2 - 1] == c[0]) {
		puts("YES");
	}	
	else puts("NO");

	return 0;
}
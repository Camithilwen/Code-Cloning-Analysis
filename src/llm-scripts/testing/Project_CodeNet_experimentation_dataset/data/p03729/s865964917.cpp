#include <stdio.h>
#include <string.h>

int main() {
	char a[15];
	char b[15];
	char c[15];
	scanf("%s %s %s", a, b, c);
	
	if(a[strlen(a)-1] == b[0] && b[strlen(b)-1] == c[0]){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}
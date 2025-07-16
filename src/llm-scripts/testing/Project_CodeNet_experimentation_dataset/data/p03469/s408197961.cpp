#include <stdio.h>
#include <string.h>

int main(){
	int y;
	char s[5];
	scanf("%d/%s", &y, s);
	printf("%d/%s", y+=1, s);
	return 0;
}
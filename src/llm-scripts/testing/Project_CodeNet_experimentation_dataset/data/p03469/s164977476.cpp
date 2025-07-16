#include <stdio.h>
 
int main() {
	char S[30];
	scanf("%[^\n]", S);
	S[3] = '8';
	printf("%s", S);
	
	return 0;
}
#include<stdio.h>
int main() {
	
	char character1[100];
	char character2[100];
	
	scanf("%s", character1);
	scanf("%s", character2);
	printf("%s%s", character2, character1);
	
	return 0;
}
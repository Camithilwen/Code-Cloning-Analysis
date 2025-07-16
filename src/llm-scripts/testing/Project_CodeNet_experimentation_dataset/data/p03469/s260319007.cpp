#include <stdio.h>

int main() {
	char kaping[14];
	scanf("%s", kaping);
	kaping[3] = '8';
	printf("%s", kaping);
	
	return 0;
}
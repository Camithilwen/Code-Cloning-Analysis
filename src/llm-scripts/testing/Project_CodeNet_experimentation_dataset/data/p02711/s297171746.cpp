#include <stdio.h>
#include <string.h>
int main() {
	char angka[10];
	scanf("%s", &angka);
	int ada = 0;

	for(int i = 0 ; i < strlen(angka); i++) {
		if (angka[i] == '7'){
			ada = 1;
		}
	}
	if (ada ==1){
		printf("Yes");
		
	}
	else {
		printf("No");
	}
	
	puts(" ");
	
	
	return 0;
}
#include <stdio.h>

int main(){
	int date[11];
	for(int i = 0; i < 10; i++){
		scanf("%c", &date[i]);
	}
	
	for(int i = 0; i < 10; i++){
		date[3] = '8';
		printf("%c", date[i]);
	}

	return 0;
}
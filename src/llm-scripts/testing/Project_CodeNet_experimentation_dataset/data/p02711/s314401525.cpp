#include <stdio.h>

int main (){
	int N;
	scanf ("%d", &N);
	
	if (N % 10 == 7 || (N/10)%10 == 7 || N /100 == 7){
		puts ("Yes");
	}
	else {
		puts ("No");
	}
	return 0;
}
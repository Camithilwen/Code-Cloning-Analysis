#include<stdio.h>

int main (){
	int number, A,B,C;
	scanf("%d", &number );
	A = number / 100;
	B = number % 100 / 10;
	C = number % 10;
	if (A == 7 || B == 7 || C == 7)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	
	return 0;
}
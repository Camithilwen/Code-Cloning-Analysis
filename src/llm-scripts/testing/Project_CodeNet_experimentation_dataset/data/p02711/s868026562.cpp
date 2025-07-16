#include <stdio.h>
int main (){
	int c;
	scanf ("%d", &c);
	int firstNumber = c / 100;
	int secondNumber = (c % 100) / 10;
	int thirdNumber = c % 10;
	if (firstNumber == 7 || secondNumber == 7 || thirdNumber == 7){
		printf ("Yes", c);
	}else{
		printf ("No", c);
	}
	return 0;
}
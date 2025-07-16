#include <stdio.h>

int main (){
	int year;
	int month;
	int date;
	int x;
	
	scanf ("%d/%d/%d", &year, &month, &date);
	
	x = year + 1;
	
	printf ("%d/%02d/%02d\n", x, month, date);
	
	return 0;
}
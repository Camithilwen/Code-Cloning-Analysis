#include<stdio.h>

int main()
{
	int day,month,year;
	scanf("%d/%d/%d",&year,&month,&day);
	printf("%d/%.2d/%.2d",year+1,month,day);
	
	
	return 0;
}
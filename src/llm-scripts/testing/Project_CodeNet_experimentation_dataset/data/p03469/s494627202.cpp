#include<stdio.h>

int main(){
	char year[10], month[5], day[5];
	scanf("%[^/]/%[^/]/%s", &year, &month, &day);
	getchar();
	printf("2018/01/%s\n", day);	
	return 0;
}
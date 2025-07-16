#include<stdio.h>

int main(){
	char date[10], month[10], year[10];
	scanf("%[^/]/%[^/]/%s", year, month, date);
	printf("2018/01/%s", date);
	return 0;
}
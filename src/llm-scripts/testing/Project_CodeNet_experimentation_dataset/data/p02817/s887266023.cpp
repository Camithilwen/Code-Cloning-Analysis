#include<stdio.h>
 
int main()
{
	char a[105];
	char b[105];
	scanf("%s %s", &a, &b);
	printf("%s%s", &b, &a);
	return 0;
}
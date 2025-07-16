#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char *p;
	char str[1000];
	scanf("%d\n",&n);
	while(n--){
	gets(str);
	for(p;p=strstr(str,"Hoshino");)p[6]='a';
	puts(str);
	}
	return 0;
}
#include <stdio.h>

int main(){
char name[12];

scanf("%[^\n]", &name);
name[3] = '8';
printf("%s", name);

	return 0;
}
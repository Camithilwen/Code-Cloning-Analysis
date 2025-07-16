#include <stdio.h>

int main(){
	char name1[110];
	char name2[110];
	
	scanf("%s%s", &name1, &name2);
	printf("%s%s", name2, name1);
	return 0;
}
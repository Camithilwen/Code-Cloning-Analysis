#include <stdio.h>

int main() {

	int a, b;
	scanf("%d %d", &a, &b);
	char s[a+b+2];
	scanf("%s", s);
	
	for(int i=0; i<a; i++){
		if(s[i]<48 || s[i]>57){
			printf("No\n");
			return 0;
		}
	}
	
	if (s[a]!=45){
		printf("No\n");
			return 0;
	}
	
	for(int i=a+1; i<=(a+b); i++){
		if(s[i]<48 || s[i]>57){
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

    return 0;
}
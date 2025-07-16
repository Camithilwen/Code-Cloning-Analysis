#include <stdio.h>

int main(void){
	int n, a[100], i, j;
	char c, s[53] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	while(1){
		scanf("%d",&n);
		if(!n) break;
		for(i = 0;i < n;i++)
			scanf("%d",&a[i]);
		getchar();
		for(i = 0;(c = getchar()) != '\n';i++){
			for(j = 0;j < 52;j++){
				if(s[j] == c)
					printf("%c",s[(52 + j - a[i % n]) % 52]);
			}
		}
		printf("\n");
	}
	return 0;
}
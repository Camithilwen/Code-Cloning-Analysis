#include <stdio.h>

int main()
{
	int j,i,n,ice[10],in;

	scanf("%d",&n);

	while(n != 0){
		for(i = 0; i < 10; i++){
			ice[i] = 0;
		}

		for(i = 0; i < n; i++){
			scanf("%d",&in);
			ice[in]++;
		}

		for(i = 0; i < 10; i++){
			if(ice[i] == 0){
				printf("-");
			}
			for(j = 0; j < ice[i]; j++){
				printf("*");
			}
			printf("\n");
		}

		scanf("%d",&n);
	}

	return 0;
}
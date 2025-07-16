#include<stdio.h>
 
int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int sum = A + B + 1;
	char str[sum];
	scanf("%s", &str);
	int ctr = 0;
	for(int i = 0; i < sum; i++){
		if(i == A){
			if(str[i] != '-'){
				printf("No\n");
				return 0;
			}
		}else{
			if(str[i] >= '0' && str[i] <= '9'){
				++ctr;
			}
		}
	}
	if(ctr == A+B){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
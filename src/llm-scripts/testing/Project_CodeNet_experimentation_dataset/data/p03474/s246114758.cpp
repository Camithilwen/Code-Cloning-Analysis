#include <stdio.h>
#include <string.h>

int main(){
	int A, B, len;
	scanf("%d %d", &A, &B);
	char S[100];
	scanf("%s", &S);
	len = strlen(S);
	if(len != A+B+1){
		printf("No\n");
		return 0;
	}
	if(S[A] == '-'){
		for(int i=0; i<len; i++){
			if(i != A){
				if(S[i] < 48 || S[i] > 57){
					printf("No\n");
					return 0;
				}
			}
		}
		printf("Yes\n");
		return 0;
	}else{
		printf("No\n");
		return 0;
	}
	return 0;
}
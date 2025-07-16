#include<stdio.h>
int main(){
	int N;
	long long int result = 0;
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; i++){
		if(i % 3!=0 && i % 5 !=0){
			result += i;
		}
	}
	if(result > 266666333332){
		printf("266666333332");
	}else{
		printf("%lld", result);
	}

	return 0;
}
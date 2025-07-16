#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long int sum =0;
	for(int i = 1 ;i<=N;i++){
		if(i%3==0 && i%5==0){
			sum +=0;
		}
		else if(i%3==0){
			sum += 0;
		}
		else if(i%5==0){
			sum+=0;
		}
		else {
			sum += i;
		}
	}
	printf("%lld",sum);
	
	return 0;
}
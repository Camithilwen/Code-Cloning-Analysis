#include<stdio.h>

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int sum1 = k/n;
	int sum2 = k/m;
	int ctr =  0;
	int temp;
	if(sum1 > sum2){
		for(int i = 1; i <= 100; i++){
			temp = m * i;
			++ctr;
			if(temp >= k){
				break;
			}
		}
	}else{
		for(int i = 1; i <= 100; i++){
			temp = n * i;
			++ctr;
			if(temp >= k){
				break;
			}
		}
	}
	printf("%d\n", ctr);
}
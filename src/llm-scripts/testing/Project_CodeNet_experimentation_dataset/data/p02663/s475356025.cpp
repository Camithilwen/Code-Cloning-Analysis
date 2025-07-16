#include<stdio.h>

int main()
{
	int h1, m1, h2, m2, k, ans;
	
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	
	int sum1 = (h1 * 60) + m1;
	int sum2 = (h2 * 60) + m2;
	
	if(sum1 > sum2){
		ans = sum1 - sum2 - k;
	}else{
		ans = sum2 - sum1 - k;
	}
	printf("%d\n", ans);
}
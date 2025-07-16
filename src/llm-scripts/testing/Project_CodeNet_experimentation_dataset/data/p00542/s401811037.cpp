#include <stdio.h>

int main(){
	int a[6],sum=0,min=100;
	for (int i=0;i<6;i++) scanf("%d",a+i);
	for (int i=0;i<6;i++) sum += a[i];
	for (int i=0;i<4;i++) min = (min > a[i])?(a[i]):(min);
	sum -= min;
	sum -= (a[4] < a[5])?a[4]:a[5];
	printf("%d\n",sum);
}
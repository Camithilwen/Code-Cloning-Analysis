#include<stdio.h>

int main(){
	int a,b,x,y,kurang;
	scanf("%d %d %d %d %d", &a,&b,&x,&y,&kurang);
	int temp=((x*60)+y)-((a*60)+b);
	printf("%d\n", temp-kurang);
	return 0;
}
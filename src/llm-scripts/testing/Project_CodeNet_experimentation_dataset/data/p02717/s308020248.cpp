#include <stdio.h>
int main(){
	int X,Y,Z;
	int *px,*py,*pz;
	scanf("%d",&X);
	scanf("%d",&Y);
	scanf("%d",&Z);
	px = &Z;
	py = &X;
	pz = &Y;
	printf("%d %d %d",*px,*py,*pz);
} 
#include<stdio.h>
int main()
{
	int N,R;
	int Z;
	scanf("%d %d",&N,&R);
	Z=100*(10-N);
	if(N>=10){
		printf("%d",R);
	}
	else if(N<10){
		printf("%d",R+Z);
	}
	return 0;
}
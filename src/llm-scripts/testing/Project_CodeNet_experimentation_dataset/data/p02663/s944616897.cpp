#include<stdio.h>

int main(){
	int N;
	int n1;
	int M;
	int m1;
	int k;
	scanf("%d %d %d %d %d",&N ,&n1,&M,&m1,&k );
	int waktu = ((M*60+m1)-(N*60+n1))-k;
	printf ("%d",waktu);
	
	
	
	return 0;
}
#include<stdio.h>
int main(void){
	int l[10],v[2];
	int sv,sl,i;
	double n;
	while(~scanf("%d",l)){
		sv=0;sl=l[0];
		for(i=1;i<=9;i++){
			scanf(",%d",l+i);
			sl+=l[i];
		}
		for(i=0;i<2;i++){
			scanf(",%d",v+i);
			sv+=v[i];
		}
		n=sl/(double)sv;
		n*=v[0];
		for(i=0;n>0;i++)n-=l[i];
		printf("%d\n",i);
	}
	return 0;
}
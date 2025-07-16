#include<stdio.h>
int main(void)
{
	int n,pm[10001],pe[10001],pj[10001],i,x[10001],y[10001];
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&pm[i],&pe[i],&pj[i]);
			x[i]=(pm[i]+pe[i])/2;
			y[i]=(pm[i]+pe[i]+pj[i])/3;
		}
		for(i=0;i<n;i++){
			if(pm[i]==100||pe[i]==100||pj[i]==100) printf("A\n");
			else if(x[i]>=90||y[i]>=80) printf("A\n");
			else if(y[i]>=70||y[i]>=50&&pm[i]>=80||pe[i]>=80) printf("B\n");
			else printf("C\n");
		}
	}
	return 0;
}	
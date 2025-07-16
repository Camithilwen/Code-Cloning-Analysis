#include<stdio.h>
int main(void)
{
	int n,pm,pe,pj,i,j,pme,pmej;
	scanf("%d",&n);
	while(n!=0){
		for(i=0;i<n;i++){
				scanf("%d %d %d",&pm,&pe,&pj);
				pme=(pm+pe)/2;
				pmej=(pm+pe+pj)/3;
				if(pm==100 || pe==100 || pj==100){
					printf("A\n");
				}
				else if(pme>=90){
					printf("A\n");
				}
				else if(pmej>=80){
					printf("A\n");
				}
				else if(pmej>=70){
					printf("B\n");
				}
				else if(pmej>=50 && pm>=80 || pe>=80){
					printf("B\n");
				}
				else {
					printf("C\n");
				}
			}
		scanf("%d",&n);
	}
	return 0;
}
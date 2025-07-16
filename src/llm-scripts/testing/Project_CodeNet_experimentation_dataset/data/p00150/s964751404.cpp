#include<stdio.h>
int main(void)
{
	int a[10001],s,d,f,g,h,i,j;
	a[1]=0;
	for(i=2;i<=10000;i++){
		a[i]=1;
	}
	for(i=2;i<=5000;i++){
		if(a[i]!=0){
			s=2;
			while(i*s<=10000){
				a[i*s]=0;
				s++;
			}
		}
	}
	/*for(i=1;i<=10000;i++){
		if(a[i]==1){
			printf("%d\n",i);
		}
	}*/
	scanf("%d",&d);
	while(d!=0){
		for(i=d;i>=1;i--){
			if(a[i-2]==1&&a[i]==1){
				printf("%d %d\n",i-2,i);
				break;
			}
		}
	scanf("%d",&d);		
	}
	return 0;
}
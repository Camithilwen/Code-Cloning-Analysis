#include<stdio.h>
int main(void)
{
	int n,m,a[1000],b[1000],c,i,j,s[1000],min,max;
	max=-1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);	
		s[i]=0;
	}
	for(j=1;j<=m;j++){
		scanf("%d",&b[j]);
	}
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++){
			if(b[j]>=a[i]){
				s[i]++;
			//	printf("i= %d j= %d a=%d\n",i,j,s[i]);		
				break;
				
			}
		}
	}	
	for(i=1;i<=n;i++){
		if(max<s[i]){
			max=s[i];
			//printf("ma=%d\n",max);
			c=i;
		//	printf("a=%d\n",a[i]);
		}
	}
	printf("%d\n",c);
	return 0;
}
	
#include<stdio.h>
int main(void)
{
	int n,m;
	int a[1001],b[1001];
	int c[1001],d;
	int max;
	int i,j;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		c[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[j]<=b[i]){
				c[j]++;
				break;
			}
		}
	}
	max=c[0];
	d=1;
	for(i=1;i<n;i++){
		if(max<c[i]){
			max=c[i];
			d=i+1;
		}
	}
	printf("%d\n",d);
	return 0;
}
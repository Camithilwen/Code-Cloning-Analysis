#include<stdio.h>
int main(void)
{
	int a,s,d,f,g,h[10001],i,j,z[10001];
	scanf("%d",&a);
	for(i=1;i<=a;i++){
		z[i]=1;
		//printf("%d\n",z[4]);
	}
//	printf("%d\n",z[4]);
	for(i=1;i<=a*(a-1)/2;i++){
		h[i]=0;
	}
	for(i=1;i<=a*(a-1)/2;i++){
		scanf("%d %d %d %d",&s,&d,&f,&g);
		if(f<g){
			h[d]=h[d]+3;
		}
		else if(f>g){
			h[s]=h[s]+3;
		}
		else if(f==g){
			h[d]++;
			h[s]++;
		}
	}
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++){
			if(h[i]<h[j]){
				z[i]++;
			//	printf("z[%d]=%d\n",i,z[i]);
			}

		}
	}
	for(i=1;i<=a;i++){
		printf("%d\n",z[i]);
	}
	return 0;
}
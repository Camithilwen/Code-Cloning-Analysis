#include<stdio.h>
int main(void)
{
	int a,s,d[10000],f[10000],g[10000],h[10000],i,j,z;
	scanf("%d",&a);
	scanf("%d",&s);
	while(a!=0&&s!=0){
	z=0;
	for(i=1;i<=s;i++){
		g[i]=0;
		h[i]=0;
	}
	for(i=1;i<=s;i++){
		scanf("%d %d",&d[i],&f[i]);
		if(d[i]==1){
			g[f[i]]=1;
			h[i]=f[i];
		}
//		printf("h==%d\n",h[i]);
	}
	for(i=1;i<=s;i++){
		for(j=1;j<=s;j++){
			if(i!=j){
				if(h[i]==d[j]){
					if(g[f[j]]!=1){
						g[f[j]]=2;
					}
				}
				if(h[i]==f[j]){
					if(g[d[j]]!=1){
						g[d[j]]=2;
					}
				}
			}
		}
	}
	for(i=1;i<=s;i++){
		if(g[i]==1||g[i]==2){
			z++;
		}
	}
	printf("%d\n",z);
	scanf("%d",&a);
	scanf("%d",&s);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	long long int g[1001],s[1001],d[1001],f[1001];
	int j,i,k,a,h[1001];
	while(1){
		scanf("%d",&a);
		if(a==0) break;
		for(i=0;i<a;i++){
			h[i]=0;
			g[i]=0;
		}
		for(i=0;i<a;i++){
			scanf("%lld %lld %lld",&s[i],&d[i],&f[i]);
			if(d[i]*f[i]>=1000000) h[i]=1;
			/*if(d[i]==1000000&&f[i]>=1) h[i]=1;
			if(f[i]==100000&&d[i]>=10) h[i]=1;*/
			if(h[i]==0) g[i]=d[i]*f[i];
			else g[i]=0;
		}
		for(i=0;i<a;i++){
			for(j=i+1;j<a;j++){
				if(g[i]>=1000000&&h[i]==0){
					h[i]=1;
				}
				if(s[i]==s[j]){
					if(h[i]==0){
						g[i]+=g[j];
						g[j]=0;
					}
					else g[j]=0;
				}
				if(g[i]>=1000000&&h[i]==0){
					h[i]=1;
				}
			}
		}
		k=0;
		for(i=0;i<a;i++){
			if(h[i]==1){
				printf("%lld\n",s[i]);
				k=1;
			}
		}
		if(k==0) printf("NA\n");
	}
	return 0;
}
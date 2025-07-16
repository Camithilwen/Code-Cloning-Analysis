#include<stdio.h>
int main(){
	int M=100000000;
	int n,m,i,u,s,c[510],f[20010],t[20010];
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0&&m==0){
			break;
		}
		for(i=u=1;i<=n;i++){
			c[i]=M;
		}
		for(i=s=c[1]=0;i<m*2;i+=2){
			scanf("%d %d",&f[i],&t[i]);
			f[i+1]=t[i];
			t[i+1]=f[i];
		}
		while(u){
			for(i=u=0;i<=m*2;i++){
				if(c[f[i]]==M||c[t[i]]<=c[f[i]]+1){
					continue;
				}
				c[t[i]]=c[f[i]]+1;
				u=1;
			}
		}
		for(i=2;i<=n;i++){
			if(c[i]<3){
				s++;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
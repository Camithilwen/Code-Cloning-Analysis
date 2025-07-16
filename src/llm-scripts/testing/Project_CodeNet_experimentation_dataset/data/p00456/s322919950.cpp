#include<stdio.h>

int main(void)
{   
	int W_t[3];
	int K_t[3];
	int i,p,l,n,m;
    int K_p=0,W_p=0;

	for(i=0;i<3;i++){
		scanf("%d",&p);
		W_t[i]=p;		
	}
	for(i=3;i<10;i++){
		for(l=0;l<2;l++)
			for(m=l+1;m<3;m++){
				if(W_t[l]<W_t[m]){
					n=W_t[l];
					W_t[l]=W_t[m];
					W_t[m]=n;
				}
			}
			scanf("%d",&p);
			if(W_t[2]<p)
				W_t[2]=p;
	}
	for(i=0;i<3;i++){
		scanf("%d",&p);
		K_t[i]=p;		
	}
	for(i=3;i<10;i++){
		for(l=0;l<2;l++)
			for(m=l+1;m<3;m++){
				if(K_t[l]<K_t[m]){
					n=K_t[l];
					K_t[l]=K_t[m];
					K_t[m]=n;
				}
			}
			scanf("%d",&p);
			if(K_t[2]<p)
				K_t[2]=p;
	}
	for(i=0;i<3;i++){
		K_p+=K_t[i];
		W_p+=W_t[i];
	}
	printf("%d %d\n",W_p,K_p);
	return 0;
}
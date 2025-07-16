#include<stdio.h>


int main(){
	int W[10],K[10],i,j,c;
	
	for(i=0;i<10;i++){
		scanf("%d",&W[i]);
	}
	for(i=0;i<10;i++){
		scanf("%d",&K[i]);
	}
	for(i=0;i<10;i++){
		for(j=i;j<10;j++){
			if(W[i]<W[j]){
				c=W[i];
				W[i]=W[j];
				W[j]=c;
			}
			if(K[i]<K[j]){
				c=K[i];
				K[i]=K[j];
				K[j]=c;
			}
		}
	}
	printf("%d %d\n",W[0]+W[1]+W[2],K[0]+K[1]+K[2]);
	return 0;
}
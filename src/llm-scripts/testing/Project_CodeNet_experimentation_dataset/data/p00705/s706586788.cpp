#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	
	int N,Q,M,Date[101],i,l,k;
	
	while(0<=scanf("%d%d",&N,&Q)){
		for(i=0;i<101;i++){
			Date[i]=0;
		}
		
		if((N==0) && (Q==0)){
			break;
		}
		
		for(k=0;k<N;k++){
			scanf("%d",&M);
			if(M==0){
				continue;
			}else{
				for(i=0;i<M;i++){
					scanf("%d",&l);
					++Date[l];
				}
			}
		}
		l=0;
		i=0;
		for(k=0;k<100;k++){
			if(i<Date[k] && Date[k]>=Q){
				i=Date[k];
				l=k;
			}
		}
		
		printf("%d\n",l);
	}
	
	return 0;
}
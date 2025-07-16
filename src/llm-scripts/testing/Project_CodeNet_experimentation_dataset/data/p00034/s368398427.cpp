#include<stdio.h>
#include<string.h>

int main(){
	int l[10],v1,v2,i;
	double sure;
	
	while(0<=scanf("%d",&l[0])){
		for(i=1;i<10;i++){
			scanf(",%d",&l[i]);
			l[i]+=l[i-1];
		}
		scanf(",%d,%d",&v1,&v2);
		
		sure=(double)v1/(double)(v1+v2)*(double)(l[9]);
		
		for(i=0;i<10;i++){
			if(sure<=l[i]){
				printf("%d\n",i+1);
				break;
			}
		}
	}
	return 0;
}
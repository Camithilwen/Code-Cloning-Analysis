#include<stdio.h>
#include<string.h>
int main(){
	int r=0,a[4],b[2],i,s=100,nf;
	scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&b[0],&b[1]);
	for(i=0;i<4;i++){
		if(s>=a[i]){
			s=a[i];
			nf=i;
		}
	}
	for(i=0;i<4;i++){
		if(i!=nf){
			r+=a[i];
		}
	}
	if(b[0]>b[1]){
		r+=b[0];
	}else{
		r+=b[1];
	}

	printf("%d\n",r);
	return 0;
}
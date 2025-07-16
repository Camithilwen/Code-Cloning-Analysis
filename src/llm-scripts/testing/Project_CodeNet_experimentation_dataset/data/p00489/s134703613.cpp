#include <stdio.h>
int main(void)
{
	int a,b=0,c=0,e,d,f,i,j,team[10000]={0},k[100]={0};
	scanf("%d",&a);
	for(i=0;i<a-1;i++){
		for(j=i;j<a-1;j++){
			b++;
		}
	}
	for(i=0;i<b;i++){
		scanf("%d %d %d %d",&c,&d,&e,&f);
		if(e>f){
			team[c]=team[c]+3;
		}
		else if(f>e){
			team[d]=team[d]+3;
		}
		else{
			team[c]=team[c]+1;
			team[d]=team[d]+1;
		}
	}
	/*for(i=1;i<a+1;i++){
		printf("%d\n",team[i]);
	}
	printf("\n");
	*/
	d=1;
	f=0;
	for(i=1000;i>0;i--){
		for(j=1;j<a+1;j++){
			if(i == team[j]){
				k[j]=d;
				f++;
			}
		}
		if(f>=1){
			d=d+f;
			f=0;
		}
	}
	for(i=1;i<a+1;i++){
		printf("%d\n",k[i]);
	}
	return 0;
}
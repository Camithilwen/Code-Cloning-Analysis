#include<stdio.h>
int x;
int d[11];
int i,j;
int main(){
	while(scanf("%d,",&x)!=EOF){
		d[0]=0;
		d[1]=d[0]+x;
		for(i=0;i<9;i++){
			scanf("%d,",&x);
			d[i+2]=d[i+1]+x;
		}
		int v1,v2;
		scanf("%d,%d",&v1,&v2);
		double p;
		int ans;
		p=(double)(d[10]*v1)/(v1+v2);
		for(i=0;i<10;i++){
			if(p>d[i]&&p<=d[i+1]){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans+1);
	}
}
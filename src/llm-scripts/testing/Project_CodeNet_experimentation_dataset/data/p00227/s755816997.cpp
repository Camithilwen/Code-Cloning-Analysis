#include<stdio.h>
int main(void)
{
	int a,s,d[2000],f,g,h,i,j;
	scanf("%d %d",&a,&s);
	while(a!=0&&s!=0){
		for(i=1;i<=a;i++){
			scanf("%d",&d[i]);
		}
		for(i=1;i<=a;i++){
			for(j=i;j<=a;j++){
				if(d[i]<d[j]){
					f=d[i];
					d[i]=d[j];
					d[j]=f;
				}
			}
		}
		g=0;
		h=0;
		for(i=1;i<=a;i++){
			if(g==s-1){
				g=0;
				d[i]=0;
			}
			else if(g!=s-1){
				g++;
				h+=d[i];
			}
			//printf("%d %d\n",g,d[i]);
		}
		printf("%d\n",h);
	scanf("%d %d",&a,&s);
	}
	return 0;
}
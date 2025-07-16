#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j,k;
int a,b,c,flag[304],n;
typedef struct result{
	int x,y,z,r;
}RESULT;
RESULT w[1005];

int main(){
	scanf("%d %d %d",&a,&b,&c);
	while(a!=0 && b!=0 && c!=0){
		for(i=1;i<=a+b+c;i++)flag[i]=2;
		scanf("\n%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d %d %d %d",&(w+i)->x,&(w+i)->y,&(w+i)->z,&(w+i)->r);
			if((w+i)->r==1){
				flag[(w+i)->x]=1;
				flag[(w+i)->y]=1;
				flag[(w+i)->z]=1;
			}
		}
		
		for(i=1;i<=n;i++){
			if((w+i)->r==0){
				if(flag[(w+i)->x]==1 && flag[(w+i)->y]==1)flag[(w+i)->z]=0;
				if(flag[(w+i)->y]==1 && flag[(w+i)->z]==1)flag[(w+i)->x]=0;
				if(flag[(w+i)->z]==1 && flag[(w+i)->x]==1)flag[(w+i)->y]=0;
			}
		}
		for(i=1;i<=a+b+c;i++)printf("%d\n",flag[i]);
		
		scanf("%d %d %d",&a,&b,&c);
	}
	return 0;
}
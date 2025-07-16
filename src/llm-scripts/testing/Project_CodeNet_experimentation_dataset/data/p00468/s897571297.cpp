#include<stdio.h>
int main(){
	int stu[501];
	int ls[2][10001];
	int c,n,m,i,j;
	
	for(;;){
		c=0;
		for(i=0;i<501;i++)stu[i]=0;
		scanf("%d",&n);
		scanf("%d",&m);
		if(n==0)break;
		
		for(i=0;i<m;i++){
			scanf("%d%d", &ls[0][i], &ls[1][i]);
			if(ls[0][i]==1)stu[ls[1][i]]=2;
			if(ls[1][i]==1)stu[ls[0][i]]=2;
		}
		
		for(i=1;i<n+1;i++){
			if(stu[i]==2){
				for(j=0;j<m;j++){
					if(ls[0][j]==i){
						if(stu[ls[1][j]]==2){}
						else stu[ls[1][j]]=1;
					}
					if(ls[1][j]==i){
						if(stu[ls[0][j]]==2){}
						else stu[ls[0][j]]=1;
					}
				}
			}
		}
		stu[1]=0;
		for(i=1;i<n+1;i++)if(stu[i]==1 || stu[i]==2)c++;
		printf("%d\n",c);
	}
	return 0;
}
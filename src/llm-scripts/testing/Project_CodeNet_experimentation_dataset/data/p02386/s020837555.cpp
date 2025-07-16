#include<stdio.h>

int main(){
	
	int n,c[101][2][7],z,Z,x;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int t=0;t<6;t++){
			scanf("%d",&c[i][1][t]);
			c[i][0][t]=t;
		}
	}
	
	for(int p=0;p<n-1;p++){
		for(int s=p+1;s<n;s++){
			
			///????????????????????????///
			
			for(int i=0;i<6;i++){
				
				///??????c[s][1][i]?????????///
				
				for(int t=0;i!=c[s][0][0];t++){
					if(t==4) break;
					z=c[s][0][0];
					Z=c[s][1][0];
					c[s][0][0]=c[s][0][4];
					c[s][1][0]=c[s][1][4];
					c[s][0][4]=c[s][0][5];
					c[s][1][4]=c[s][1][5];
					c[s][0][5]=c[s][0][1];
					c[s][1][5]=c[s][1][1];
					c[s][0][1]=z;
					c[s][1][1]=Z;
				}
				if(i!=c[s][0][0]){
					for(int t=0;i!=c[s][0][0];t++){
						if(t==4) break;
						z=c[s][0][0];
						Z=c[s][1][0];
						c[s][0][0]=c[s][0][2];
						c[s][1][0]=c[s][1][2];
						c[s][0][2]=c[s][0][5];
						c[s][1][2]=c[s][1][5];
						c[s][0][5]=c[s][0][3];
						c[s][1][5]=c[s][1][3];
						c[s][0][3]=z;
						c[s][1][3]=Z;
					}
				}
				///a[]??¨????????????????????´??¢?????????///
				
				for(int t=0;t<4;t++){
					x=0;
					for(int t=0;t<6;t++){
						if(c[p][1][t]!=c[s][1][t]){
							x++;
						}
					}
					//printf("%d\n",x);
					if(x==0) break;
					
					Z=c[s][1][1];
					c[s][1][1]=c[s][1][3];
					c[s][1][3]=c[s][1][4];
					c[s][1][4]=c[s][1][2];
					c[s][1][2]=Z;
				}
				if(x==0) break;
			}
			if(x==0) break;
		}
		if(x==0) break;
	}
	if(x==0){
		printf("No\n");
	}
	else printf("Yes\n");
	return 0;
}
#include<stdio.h>
void fanc(int,int);
	int map[13][13];
int main(void)
{
	int i,j;
	int c;
	char s[13];
	
	while(scanf("%s",s)!=EOF){
		c=0;
		for(i=0;i<12;i++){
			map[0][i]=s[i]-'0';
		}
		for(i=1;i<12;i++){
			scanf("%s",s);
			for(j=0;j<12;j++){
				map[i][j]=s[j]-'0';
			}
		}
	/*	for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				printf("%d ",map[i][j]);
			}
			printf("\n");
		}*/
		for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				if(map[i][j]==1){
					c++;
					map[i][j]=0;
					fanc(i,j);
				}
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
void fanc(int x,int y)
{
	if(x+1<12){
		if(map[x+1][y]==1){
			map[x+1][y]=0;
			fanc(x+1,y);
		}
	}
	if(x-1>=0){
		if(map[x-1][y]==1){
			map[x-1][y]=0;
			fanc(x-1,y);
		}
	}
	if(y+1<12){
		if(map[x][y+1]==1){
			map[x][y+1]=0;
			fanc(x,y+1);
		}
	}
	if(y-1>=0){
		if(map[x][y-1]==1){
			map[x][y-1]=0;
			fanc(x,y-1);
		}
	}
}
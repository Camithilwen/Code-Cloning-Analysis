#include<stdio.h>
#include<string.h>
#include<math.h>
void p(int,int);
int a,s,d[4]={0,-1,0,1},f[4]={-1,0,1,0},g,h,c,x;
char z[13][13];
int main(void)
{
	int i,j;
	while(scanf("%s",z[0])!=EOF){
		for(i=1;i<12;i++) scanf("%s",z[i]);
		g=0;
		for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				if(z[i][j]=='1'){
					g++;
					p(i,j);
				}
			}
		}
		printf("%d\n",g);
	}
}
void p(int x,int c)
{
	int i,j;
	z[x][c]='0';
	for(i=0;i<4;i++){
		if(x+d[i]<12&&x+f[i]>=0&&z[x+d[i]][c]=='1') p(x+d[i],c);
		if(c+d[i]>=0&&c+f[i]<12&&z[x][c+f[i]]=='1') p(x,c+f[i]);
	}
}
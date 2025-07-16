#include<stdio.h>
#include<string.h>
void haichi(void);
void Block(int,int);
int c,d,x,y,xg,yg,M,Flag;
int MAP[101][101],MF[101][101];
int main(void)
{
	int w,h,xs,ys,n;
	while(1){
		Flag=0;
		memset(MAP,0,sizeof(MAP));
		memset(MF,0,sizeof(MF));
		scanf("%d %d",&w,&h);
		if(w == 0 && h == 0) break;
		scanf("%d %d %d %d",&xs,&ys,&xg,&yg);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&c,&d,&x,&y);
			haichi();
		}
		/*for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				printf("%d",MAP[i][j]);
			}
			printf("\n");
		}*/
		M = MAP[ys][xs];//
		if(MAP[ys][xs] == MAP[yg][xg])
			Block(xs,ys);
		if(Flag==1)
			printf("OK\n");
		else
			printf("NG\n");
	}
	return 0;
}

void haichi(void)
{
	if(d==0){
		MAP[y][x]=c;MAP[y][x+1]=c;MAP[y][x+2]=c;MAP[y][x+3]=c;
		MAP[y+1][x]=c;MAP[y+1][x+1]=c;MAP[y+1][x+2]=c;MAP[y+1][x+3]=c;
	}
	else if(d==1){
		MAP[y][x]=c;MAP[y][x+1]=c;
		MAP[y+1][x]=c;MAP[y+1][x+1]=c;
		MAP[y+2][x]=c;MAP[y+2][x+1]=c;
		MAP[y+3][x]=c;MAP[y+3][x+1]=c;
	}
}

void Block(int X,int Y)
{
	MF[Y][X] = 1;
	//printf("%d",M);
	if(X == xg && Y == yg)
		Flag = 1;
	if(MAP[Y-1][X] == M && MF[Y-1][X] == 0) Block(X,Y-1); //???
	if(MAP[Y+1][X] == M && MF[Y+1][X] == 0) Block(X,Y+1); //???
	if(MAP[Y][X-1] == M && MF[Y][X-1] == 0) Block(X-1,Y); //???
	if(MAP[Y][X+1] == M && MF[Y][X+1] == 0) Block(X+1,Y); //???
}
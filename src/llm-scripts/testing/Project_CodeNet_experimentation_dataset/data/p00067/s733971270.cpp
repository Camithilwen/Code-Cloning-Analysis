#include<stdio.h>
#include<algorithm>
using namespace std;
char map[15][15],moji[15];
void func(int ,int);
int main(void){
	int i,j;
	while(1){
		for(i=0;i<12;i++){
			if(scanf("%s",map[i])==EOF){
				return 0;
			}
		}
		/*for(i=0;i<=12;i++){
			printf("%s",map[i]);
		}
		printf("\n");*/
		int cnt=0;
		for(i=0;i<12;i++){
			for(j=0;j<12;j++){
				if(map[i][j]=='1'){
					map[i][j]=0;
					func(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}
void func(int y,int x){
	int i,j;
	int xx,yy;
	int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	for(i=0;i<4;i++){
		xx=x+dx[i]; 
		yy=y+dy[i];
		if(map[yy][xx]=='1' && xx<=12 && xx>=0 && yy<=12 && yy>=0){
			map[yy][xx]=0;
			func(yy,xx);
		}
	}
}
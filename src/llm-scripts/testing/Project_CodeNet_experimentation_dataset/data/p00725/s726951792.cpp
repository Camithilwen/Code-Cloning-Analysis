#include<stdio.h>

int h,w;
int map[20][20];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int ans;
int out(int y,int x){
	return y<0||h<=y||x<0||w<=x;
}
void search(int depth,int y,int x){
	int i,ny,nx;
	if(ans <= depth)return;
	for(i=0;i<4;i++){
		ny = y+dy[i];
		nx = x+dx[i];
		if(out(ny,nx) || map[ny][nx]==1)continue;
		do{
			if(map[ny][nx]==3){
				ans = depth;
				return;	
			}
			ny += dy[i];
			nx += dx[i];
		}while(!out(ny,nx) && map[ny][nx]!=1);
		if(!out(ny,nx) && map[ny][nx]==1){
			map[ny][nx]=0;
			search(depth+1,ny-dy[i],nx-dx[i]);
			map[ny][nx]=1;	
		}
	}
}
int main(){
	int i,j;
	int sy,sx;
	while(scanf("%d%d",&w,&h), w|h){
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==2){
					sy=i;sx=j;
				}
			}
		}
		ans=11;
		search(1,sy,sx);
		printf("%d\n",ans==11?-1:ans);
	}
}
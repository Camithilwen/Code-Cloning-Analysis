#include<cstdio>
#include<cstring>
#include<stack>
struct p{
	int x;
	int y;
};
using namespace std;
int main(){
	int w,h,sx,sy,gx,gy,n,c,d,x,y,i,j,k,o;
	int map[100][100];
	int used[100][100];
	int mx[4]={-1,0,1,0};
	int my[4]={0,-1,0,1};
	p v,u;
	stack<p> s;
	while(1){
		scanf("%d %d",&w,&h);
		if(w==0&&h==0){
			break;
		}
		memset(map,0,sizeof(map));
		memset(used,0,sizeof(used));
		scanf("%d %d",&sx,&sy);
		sx--;
		sy--;
		scanf("%d %d",&gx,&gy);
		gx--;
		gy--;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d %d %d %d",&c,&d,&x,&y);
			x--;
			y--;
			if(!d){
				for(j=y;j<y+2;j++){
					for(k=x;k<x+4;k++){
						map[j][k]=c;
					}
				}
			}
			else{
				for(j=y;j<y+4;j++){
					for(k=x;k<x+2;k++){
						map[j][k]=c;
					}
				}
			}
		}
		if(map[sy][sx]!=map[gy][gx]){
			printf("NG\n");
			continue;
		}
		v.x=sx;
		v.y=sy;
		s.push(v);
		o=0;
		while(!s.empty()){
			v=s.top();
			s.pop();
			if(used[v.y][v.x]){
				continue;
			}
			else{
				used[v.y][v.x]=1;
			}
			if(v.x==gx&&v.y==gy){
				o=1;
				while(!s.empty()){
					s.pop();
				}
				break;
			}
			for(i=0;i<4;i++){
				u=v;
				u.x+=mx[i];
				u.y+=my[i];
				if(u.x>=0&&u.x<w&&u.y>=0&&u.y<h&&map[u.y][u.x]==map[sy][sx]){
					s.push(u);
				}
			}
		}
		if(o){
			printf("OK\n");
		}
		else{
			printf("NG\n");
		}
	}
	return 0;
}
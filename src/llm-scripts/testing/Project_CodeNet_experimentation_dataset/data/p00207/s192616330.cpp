#include<iostream>
#include<cstdio>
using namespace std;
	int u[150][150],p,v[150][150],xg,yg,q,dx[]={1,0,-1,0},dy[]={0,1,0,-1},w,h;
void ret(int x,int y){
	int a,b,i;
	v[y][x]=1;
	if(xg==x&&yg==y)
		p++;
	else
	for(i=0;i<4;i++){
		a=x+dx[i];
		b=y+dy[i];
		if(a<1||a>w||b<1||b>h||v[b][a]==1)
			continue;
		else if(u[b][a]==q)
			ret(a,b);
	}
}
int main(){
	int xs,ys,c,d,x,y,n;
	while(cin>>w>>h,w||h){
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			v[i][j]=0;
		scanf("%d %d",&xs,&ys);
		scanf("%d %d",&xg,&yg);
		scanf("%d",&n);
		for(int k=0;k<n;k++){
			scanf("%d %d %d %d",&c,&d,&x,&y);
			if(d==0)
				for(int i=0;i<2;i++)
				for(int j=0;j<4;j++)
				u[i+y][j+x]=c;
			else 
				for(int i=0;i<4;i++)
				for(int j=0;j<2;j++)
				u[i+y][j+x]=c;
		}
		q=u[ys][xs];
		p=0;
		ret(xs,ys);
		if(p>0)
			printf("OK\n");
		else printf("NG\n");
	}
	return 0;
}
#include<iostream>
using namespace std;
#define MAX 100
#define BLANK 0
#define LONG 4
#define SHORT 2
#define HORIZONTAL 0
#define VERTICAL 1
#define VISITED 9

int field[MAX+2][MAX+2];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void rec(int x,int y,int c)
{
  int i;
  if(field[x][y]!=c)return;
  field[x][y]=VISITED;
  for(i=0;i<4;i++)rec(x+dx[i],y+dy[i],c);
  return;
}

int main()
{
  int w,h,xs,ys,xg,yg,n,c,d,x,y;
  int i,j;
  while(cin>>w>>h>>xs>>ys>>xg>>yg>>n,w|h){
    for(j=1-1;j<=h+1;j++)for(i=1-1;i<=w+1;i++)field[i][j]=BLANK;
    while(n-->0){
      cin>>c>>d>>x>>y;
      if(d==HORIZONTAL)
	for(i=0;i<LONG;i++)for(j=0;j<SHORT;j++)field[x+i][y+j]=c;
      else
	for(i=0;i<SHORT;i++)for(j=0;j<LONG;j++)field[x+i][y+j]=c;
    }
    if(field[xs][ys]!=BLANK)rec(xs,ys,field[xs][ys]);
    puts(field[xg][yg]==VISITED?"OK":"NG");
  }
}
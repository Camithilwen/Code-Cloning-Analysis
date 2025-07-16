#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pr;
int main() {
	// your code goes here
	int w,h;
	while(cin >> w >> h && w!=0){
	int xs,ys,xg,yg,n,m,s,sum,c,d,x,y;
	int dx[]={0,1,-1,0},dy[]={1,0,0,-1};
	cin >> xs>>ys>>xg>>yg >> n;
	bool map[102][102]={};	
	int color[102][102]={};
	queue<pr> q;
		color[xs][ys]=10;
		for(int i=0;i<n;i++){
			cin >> c >> d >>x >> y;
			for(int j=0;j<2+d*2;j++)
				for(int k=0;k<4-d*2;k++)
					color[x+k][y+j]=c;
		}
		map[xs][ys]=true;
		q.push(pr(xs,ys));
		while(!q.empty()){
			int f=q.front().first,s=q.front().second;
			q.pop();
			for(int i=0;i<4;i++){
					if(color[f][s]==color[f+dx[i]][s+dy[i]] && !map[f+dx[i]][s+dy[i]]){
						q.push(pr(f+dx[i],s+dy[i]));
						map[f+dx[i]][s+dy[i]]=true;
					}
			}
		}
		if(map[xg][yg])
		cout << "OK" << endl;
		else
		cout << "NG" << endl;
	}
	return 0;
}
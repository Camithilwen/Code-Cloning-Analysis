#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;


int main() {
	int h,w;
	cin>>h>>w;
	vector<vector<bool>>map(h,vector<bool>(w));
	queue<pair<pair<int,int>,int>>todo;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char c;
			cin>>c;
			if(c=='.'){
				map[i][j]=true;
			}else{
				todo.push(pair<pair<int,int>,int>(pair<int,int>(i,j),0));
			}
		}
	}
	int ans=0;
	int dx[]={1,0,-1,0};
	int dy[]={0,1,0,-1};
	while(todo.empty()!=1){
		ans++;
		auto tmp=todo.front();
		todo.pop();
		int x=tmp.first.first,y=tmp.first.second;
		int depth=tmp.second;
		ans=depth;
		for(int k=0;k<4;k++){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(nx<0||nx>=h||ny<0||ny>=w)continue;
			if(map[nx][ny]){
				map[nx][ny]=false;
				todo.push(pair<pair<int,int>,int>(pair<int,int>(nx,ny),depth+1));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
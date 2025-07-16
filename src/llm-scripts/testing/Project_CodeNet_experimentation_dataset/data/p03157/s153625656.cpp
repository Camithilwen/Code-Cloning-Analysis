#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	int h,w;
	char c[400][400];
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>c[i][j];
		}
	}
	int dx[4]={-1,0,1,0};
	int dy[4]={0,-1,0,1};
	int cnt=0;
	int id[400][400];
	bool used[400][400]={};
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(used[i][j]){
				continue;
			}
			id[i][j]=cnt;
			used[i][j]=1;
			queue<pair<int,int> > que;
			que.push(make_pair(i,j));
			while(!que.empty()){
				int x=que.front().first;
				int y=que.front().second;
				que.pop();
				for(int i=0;i<4;i++){
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(0<=nx&&nx<h&&0<=ny&&ny<w&&!used[nx][ny]){
						if(c[nx][ny]!=c[x][y]){
							used[nx][ny]=1;
							id[nx][ny]=cnt;
							que.push(make_pair(nx,ny));
						}
					}
				}
			}
			cnt++;
		}
    }
	long long sum[160001][2]={};
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(c[i][j]=='#'){
				sum[id[i][j]][0]++;
			}else{
				sum[id[i][j]][1]++;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<cnt;i++){
		ans+=sum[i][0]*sum[i][1];
	}
	cout<<ans<<endl;
	return 0;
}

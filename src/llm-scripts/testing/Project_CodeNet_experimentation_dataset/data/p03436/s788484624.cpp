#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int h,w;
int arr[105][105];
bool visited[105][105];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	int white=0;
	cin>>h>>w;
	for(int i=1; i<=h; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='.'){
				arr[i][j+1] = 1;
				white++;
			}
		}
	}
	queue<pair<pi,int> >q;
	q.push(make_pair(pi(1,1),1));
	visited[1][1] = true;
	while(!q.empty()){
		pair<pi,int> curr = q.front();
		int y = curr.first.first;
		int x = curr.first.second;
		int d = curr.second;
		q.pop();
		if(y==h && x==w){
			cout<<white-d;
			return 0;
		}
		for(int i=0; i<4; i++){
			int yy = y+dy[i];
			int xx = x+dx[i];
			if(yy<1 || xx<1 || yy>h || xx>w) continue;
			if(!visited[yy][xx] && arr[yy][xx]){
				visited[yy][xx] = true;
				q.push(make_pair(pi(yy,xx),d+1));
			}
		}
	}
	cout<<-1;
}
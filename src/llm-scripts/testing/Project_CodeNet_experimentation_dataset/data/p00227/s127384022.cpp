#include<iostream>
#include<queue>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
	int n,m,dt;
	while(1){
		cin>>n>>m;
		if(!(n&&m))break;
		priority_queue<int> que;
		rep(i,n){cin>>dt;que.push(dt);}
		int cnt=0,sum=0;
		while(!que.empty()){
			cnt++;
			if(cnt!=m)sum+=que.top();
			else cnt=0;
			que.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
}
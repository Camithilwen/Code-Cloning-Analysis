#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PA;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<PA> que;
int main(){
  int n,ans;
  char m[13][13];
  
  while(cin >> m[0]){
    
    for(int j = 0;j < 12;j++){
      if(j==0) continue;
      cin >> m[j];
    }
    ans = 0;
    for(int j = 0;j < 12;j++){
      for(int k = 0;k < 12;k++){
	if(m[j][k] == '1'){
	  que.push(PA(j,k));
	  while(!que.empty()){
	    PA p=que.front();que.pop();
	    m[p.first][p.second] = '0';
	    for(int l = 0;l < 4;l++){
	      int y = p.first+dy[l];
	      int x = p.second+dx[l];
	      if(x<0||y<0||x>=12||y>=12||m[y][x]=='0') continue;
	      que.push( PA(y,x) );
	    }
	  }
	  ans++;
	}
      }
    }
    cout << ans << endl;
  }
  return (0);
}
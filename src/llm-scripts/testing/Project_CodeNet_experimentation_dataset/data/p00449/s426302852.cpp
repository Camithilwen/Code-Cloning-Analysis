#include <iostream>
#include <algorithm>
using namespace std;
int mp[101][101];
bool flg[101] ={};
int n,q;
int dis[101];

int sssp(int s,int g) {
  for(int i=1;i<=n;i++) dis[i] = 1000000000,flg[i] = 0;
  //flg[s] = 1;
  dis[s] = 0;
  int ima;

  while(1) {
    int mindis = 1000000000;
   
    for(int i=1;i<=n;i++)
      if(mindis > dis[i] && flg[i] == 0) {
	ima = i;
	mindis = dis[i];
      }

    if(mindis == 1000000000) return -1;    
    flg[ima] = 1;
    if(ima == g) return dis[ima];


    for(int i=1;i<=n;i++) 
      if(dis[i] >dis[ima] + mp[ima][i] && mp[ima][i] != -1) 
	dis[i] = dis[ima]+mp[ima][i];
    
  }

  return dis[g];
}


int main() {

  while(1) {
  cin >> n >> q;
  if(n == 0 && q == 0) break;

  for(int i=0;i<=n;i++){ 
    //    dis[i] = 1000000000;
    //flg[i] = 0;
    for(int j=0;j<=n;j++)
      mp[i][j] = -1; 
  }

  bool sta;
  int s,g,c;
  for(int i=0;i<q;i++) {
    cin >> sta;
    if(sta == 0) {
      cin  >> s >> g;
      //for(int i=1;i<=n;i++) if(mp[s][i] !=-1)dis[i] = mp[s][i];
      int ans = sssp(s,g);
      cout << ans<< endl;
    }
    else {
      cin >> s >> g >> c;
      if(mp[s][g] != -1) {
	mp[s][g] = min(c ,mp[s][g]);
	mp[g][s] = min( mp[g][s] ,c);      
      }
      else {
	mp[s][g] = c;
	mp[g][s] = c;
      }
      
    }
  }
  }
  
  
  return 0;
  
  }
      
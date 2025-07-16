#include<bits/stdc++.h>
using namespace std;

int n, x[1<<18], y[1<<18];
char d[1<<18];

void Rotate(){
  for(int i = 1; i <= n; i++){
    int cx = y[i],cy = 200000-x[i],cz;
    if(d[i] == 'U') cz = 'R';
    if(d[i] == 'R') cz = 'D';
    if(d[i] == 'D') cz = 'L';
    if(d[i] == 'L') cz = 'U';
    x[i] = cx; y[i] = cy; d[i] = cz;
  }
}

vector<pair<int,char>> v1[1<<19];
vector<pair<int,char>> v2[1<<19];

int solve_01(){
  int ans = (1 << 24);
  for(int i = 0; i <= 500000; i++) v1[i].clear();
  for(int i = 1; i <= n; i++){
    if(!(d[i] == 'R' || d[i] == 'U')) continue;
    v1[x[i]+y[i]].push_back(make_pair(x[i],d[i]));
  }
  for(int i = 0; i <= 500000; i++){
    sort(v1[i].begin(),v1[i].end());
    for(int j = 0; j < (int)v1[i].size() - 1; j++){
     if(!(v1[i][j].second == 'R' && v1[i][j+1].second == 'U')) continue;
     ans = min(ans,v1[i][j+1].first - v1[i][j].first);
    }
  }
   return ans * 10;
}

int solve_02(){
  int ans = (1 << 24);
  for(int i = 0; i <= 500000; i++) v2[i].clear();
  for(int i = 1; i <= n; i++){
    if(!(d[i] == 'L' || d[i] == 'R')) continue;
    v2[y[i]].push_back(make_pair(x[i],d[i]));
  }
  for(int i = 0; i <= 500000; i++){
    sort(v2[i].begin(),v2[i].end());
    for(int j = 0; j < (int) v2[i].size()-1; j++){
      if(!(v2[i][j].second == 'R' && v2[i][j+1].second == 'L')) continue;
      ans = min(ans,v2[i][j+1].first - v2[i][j].first);
    }
  }
  return ans*5;
 }

 int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> d[i];
  int fans = (1 << 24);
  for(int i = 1; i <= 4; i++){
    int val1 = solve_01(); fans = min(fans,val1);
    int val2 = solve_02(); fans = min(fans,val2);
    Rotate();
  }
  if(fans == (1 << 24)) cout << "SAFE" << endl;
  else cout << fans << endl;
  return 0;
}
#include<iostream>
#include<string>
using namespace std;

string data[22];

int solve(int x, int y){

  if(x < 0 || y < 0 || x == 12 || y == 12 || data[y][x] == '0') return 0;

  data[y][x] = '0';

  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  for(int i=0;i<4;i++) solve(x+dx[i], y+dy[i]);

  return 1;
}
    
int main(){

  while(cin >> data[0]){
    for(int i=1;i<12;i++) cin >> data[i];

    int ans = 0;
    for(int i=0;i<12;i++) for(int j=0;j<12;j++) ans += solve(i, j);

    cout << ans << endl;
  }

}
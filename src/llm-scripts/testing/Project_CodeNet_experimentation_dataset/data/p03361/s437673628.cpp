#include <iostream>
#include <vector>
using namespace std;
int main(){
  int i,j;
  int h,w;
  cin >> h >> w;
  vector<vector<char>> v(h+2,vector<char>(w+2,'.'));
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      cin >> v[i][j];
    }
  }
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(v[i][j]=='#'){
        if(v[i][j+1]!='#'&&v[i][j-1]!='#'&&v[i+1][j]!='#'&&v[i-1][j]!='#'){
          cout << "No" << "\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes" << "\n";
  return 0;
}

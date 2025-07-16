#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h,w; //h side w vertical
  cin >> h >> w;
  
  char s[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> s[i][j];
    }
  }
  
  int flag = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        if(s[i-1][j] == '#' && i != 0){
          continue;
        }else if(s[i][j-1] == '#' && j != 0){
          continue;
        }else if(s[i][j+1] == '#' && j != w-1){
          continue;
        }else if(s[i+1][j] == '#' && i != h-1){
          continue;
        }else{
          flag = 1;
          break;
        }//else
      }//if
    }//for
    if(flag == 1){
      break;
    }
  }//for
  
  if(flag == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}

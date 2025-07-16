#include<iostream>

using namespace std;

int main(){
  string in;
  // while(cin >> in){
  cin >> in;
  int num[3] = {0,0,0};
  int lev = 0;
  int status = 3;
  for(int i = 0; i < in.length(); i++){
    if(in[i] == 'J'){
      //cout << num[0] << " " << num[1] << " " << num[2] << endl;
      if(status != 0) num[0] = num[1] = num[2] = 0;
      num[0]++;
      status = 0;
      continue;
    }
    if(in[i] == 'O' && (status == 0 || status == 1)){
      num[1]++;
      status = 1;
      continue;
    }
    if(in[i] == 'I' && (status == 1 || status == 2)){
      num[2]++;
      status = 2;
      if(num[1] <= num[0] && num[1] <= num[2]) lev = max(lev,num[1]);
      continue;
    }
    status = 3;
  }
  cout << lev << endl;
  // }
  return 0;
}
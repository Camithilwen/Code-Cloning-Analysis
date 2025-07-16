#include<bits/stdc++.h>
//今日も20分で解けなかったので、他の方のプログラムで勉強させていただきました。
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  int num_max,num_min;
  for(int i = 0; i < M; i++){
    if(i ==0 ){
      cin >> num_max >> num_min;
    }else{
      int a,b;
      cin >> a >> b;
      if(num_max < a){num_max = a;}
      if(num_min > b){num_min = b;}
    }
  }
  if((num_min-num_max) < 0){
   cout << 0;
  }else{
    cout << num_min-num_max+1;
  }
}
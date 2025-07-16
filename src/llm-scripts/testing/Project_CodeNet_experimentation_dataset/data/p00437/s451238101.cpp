#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int a, b, c, N;
  int flag[3][1000], judge[1000], info[301];

  while(cin >> a >> b >> c , a+b+c){
    fill_n(info,301,2);
    cin >> N;
    for(int i = 0 ; i < N ; i++ ){
      for(int j = 0 ; j < 3 ; j++) cin >> flag[j][i];
      cin >> judge[i];
      if(judge[i] == 1) for(int j = 0 ; j < 3 ; j++ ) info[flag[j][i]] = 1;
    }
    for(int i = 0 ; i < N ; i++ ){
      if(!judge[i]){
        for(int j = 0 ; j < 3 ; j++){
          if(info[flag[j][i]] == 1 && info[flag[(j+1)%3][i]] == 1){
            info[flag[(j+2)%3][i]] = 0;
          }
        }
      }
    }
    for(int i = 1 ; i <= a+b+c ; i++ ) cout << info[i] << endl;
  }
}
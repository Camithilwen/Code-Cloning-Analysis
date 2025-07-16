#include<iostream>
#include<vector>
using namespace std;

int main(){

  int num, v, n, m, len, cnt;
  vector<long long> vc[2];

  while(cin >> n){
    if(n == 0) break;
    vc[0].clear();
    vc[1].clear();
    len = 0;

    for(int i=0; i<n; i++){
      cin >> num >> v >> m;
      for(int j=0; j<=len; j++){
        if(j == len){
          vc[0].push_back(num);
          vc[1].push_back((long long)v * m);
          len++;
          break;
        }
        if(vc[0][j] == num){
          if(vc[1][j] < 1000000){
            vc[1][j] += (long long)v * m;
          }
          break;
        }
      }
    }
    
    cnt = 0;
    for(int i=0; i<len; i++){
      if(vc[1][i] >= 1000000){
        cout << vc[0][i] << endl;
        cnt++;
      }
    }
    if(cnt == 0) cout << "NA" << endl;

  }

  return 0;

}
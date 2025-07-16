#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  int q = 0;
  int cnt = 0;
  int left = 0, right = n;
  vector<int> es(n);
  while(true) {
    cout << q << endl;
    string tmp;
    cin >> tmp;
    if(tmp == "Vacant"){
      return 0;
    }else if(tmp =="Male"){
      if(cnt == 0) {
        for(int i = 0; i < n; i++){
          if(i % 2 == 0){
            es[i] = 0;
          }else{
            es[i] = 1;
          }
        }
      } else {
        if(es[q] == 0){
          left = q;
        } else {
          right = q;
        }
      }
    }else{
      if(cnt == 0) {
        for(int i = 0; i < n; i++){
          if(i % 2 == 0){
            es[i] = 1;
          }else{
            es[i] = 0;
          }
        }
      } else {
        if(es[q] == 1){
          left = q;
        } else {
          right = q;
        }
      }
    }
    q = (left + right) / 2;
    cnt++;
  }
  return 0;
}
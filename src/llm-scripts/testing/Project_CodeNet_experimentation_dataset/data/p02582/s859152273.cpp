#include <bits/stdc++.h>
using namespace std;

int main(){
  string sa;
  cin >> sa;
  int chain = 0;
  int ma = 0;
  for (char j : sa){
    if (j == 'R'){
      chain ++;
    }else chain = 0;
    ma = max(ma,chain);
  }
  cout << ma << endl;
}
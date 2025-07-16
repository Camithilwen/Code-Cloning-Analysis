#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<bool> p(60000,true);
  for(int i = 2; i < 55560; i++){
    if(!p[i]) continue;
    for(int j = 2; j*i < 55560; j++){
      p[i*j] = false;
    }
  }
  vector<int> fp;
  for(int i = 2; i < 55560; i++){
    if(p[i] && i % 5 == 1) fp.push_back(i);
  }
  for(int i = 0; i < n; i++){
    cout << fp[i] << " ";
  }
}
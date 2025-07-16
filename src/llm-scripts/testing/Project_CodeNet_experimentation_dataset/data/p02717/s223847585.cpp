#include<bits/stdc++.h>
using namespace std;

int main(void){
  int cp;
  int hako[3];
  for(int i = 0; i < 3; i++)
    cin >> hako[i];
  for(int i = 1; i < 3; i++){
    cp = hako[i];
    hako[i] = hako[0];
    hako[0] = cp;
  }
  for(int i = 0; i < 3; i++){
    cout << hako[i] << " ";
  }
  cout << "\n";
  return 0;
}
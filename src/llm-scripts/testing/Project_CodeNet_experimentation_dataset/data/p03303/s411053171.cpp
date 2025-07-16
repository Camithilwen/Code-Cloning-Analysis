#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int W;
  cin >> S >> W;
  for(int i=0;i<S.size();i+=W){
    cout << S.at(i);
  }
  cout << endl;
}
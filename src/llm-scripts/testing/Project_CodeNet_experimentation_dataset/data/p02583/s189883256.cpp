#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  if(N < 3){
    cout << "0" << endl;
    return 0;
  }
  vector<int> a(N);
  for(int i = 0;i < N;i++){
    cin >> a.at(i);
  }
  int count = 0;
  for(int j = 2;j < N;j++){
    for(int k = 1;k < j;k++){
      for(int l = 0;l < k;l++){
        if((a.at(j) == a.at(k)) || (a.at(k) == a.at(l)) || (a.at(l) == a.at(j)))continue;
        if((a.at(j) < a.at(k) + a.at(l)) && (a.at(k) < a.at(l) + a.at(j)) && (a.at(l) < a.at(j) + a.at(k)))count++;
      }
    }
  }
  cout << count <<endl;
  
}
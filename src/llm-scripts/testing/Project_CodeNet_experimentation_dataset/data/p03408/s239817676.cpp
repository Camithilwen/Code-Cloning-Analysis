#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N;
  vector<string> blue(N);
  int MAX = 0;
  
  for(int i = 0; i < N; i++){
     cin >> blue.at(i);
  }
  
  cin >> M;
  vector<string> red(M);
  
  for(int i = 0; i < M; i++){
    cin >> red.at(i);
  }
  
  int count;
  string S;
  
  for(int i = 0; i < N; i++){
    count = 0;
    S = blue.at(i);
    for(int j = 0; j < N; j++){
      if(S == blue.at(j)){
        count++;
      }
    }
   for(int k = 0; k < M; k++){
     if(S == red.at(k)){
       count--;
     }
   }
   if(MAX < count){
     MAX = count;
   }
  
  }
  
  if(MAX < 1){
    cout << 0 << endl;
  }else{
  cout << MAX << endl;
  }
    
}
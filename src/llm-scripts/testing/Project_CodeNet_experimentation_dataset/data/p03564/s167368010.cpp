#include <bits/stdc++.h>
using namespace std;
int main(){
 int N,K;
  cin >> N >> K;
  int X = 1;
   for(int i = 0; i < N; i++){
    if( X * 2 < X + K ){
     X = X * 2;
    }
    else{
     X = X + K;
    }
  }
  cout << X << endl;
}
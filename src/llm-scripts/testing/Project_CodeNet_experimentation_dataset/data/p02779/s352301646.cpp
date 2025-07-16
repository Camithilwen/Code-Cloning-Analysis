#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i=0; i<N ;i++){
    cin >> A.at(i);
  }
  
  sort(A.begin(),A.end());
  
  int x=0;
  
  for(int i=0; i<N-1 ; i++){
    if(A.at(i)==A.at(i+1)){
      cout << "NO" << endl;
      x=1;
      break;
    }
  }
  
  
  
  if(x==0){
    cout << "YES" << endl;
  }
  
  
}


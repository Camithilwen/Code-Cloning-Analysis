#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A.at(i);
  
  for(int k=0;k<K;k++){
    vector<int> B(N+1,0);
    
    for(int i=0;i<N;i++){
      int left = max(0,i-A.at(i));
      int right = min(i+A.at(i)+1,N);
      B.at(left) ++;
      B.at(right) --;
    }
    for(int i=1;i<=N;i++){
      B.at(i) += B.at(i-1);
    }
    if(A==B) break;
    A = B;
  }
  for(int i=0;i<N;i++){
    cout << A.at(i) << endl;
  }
}
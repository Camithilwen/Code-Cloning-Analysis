#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  vector<int> W(N,0);
  for(int i=0;i<N;i++){
    if(i==0 && S.at(i)=='W') W.at(i) = 1;
    else if(i==0 && S.at(i)=='E') W.at(i) = 0;
    else if(S.at(i)=='W') W.at(i) = W.at(i-1) +1;
    else W.at(i) = W.at(i-1);
  }
  int p_min = 0;
  for(int i=0;i<N;i++){
    if(i==0) p_min = N - 1 - W.at(N-1) + W.at(i);
    else if(p_min > W.at(i-1) + ( N - (i+1) ) - ( W.at(N-1) - W.at(i) ) ){
      p_min = W.at(i-1) + ( N - (i+1) ) - ( W.at(N-1) - W.at(i) );
    }
  }
  cout << p_min << endl;
}
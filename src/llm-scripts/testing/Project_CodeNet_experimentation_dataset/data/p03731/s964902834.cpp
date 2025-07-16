#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin >> N >> T;
  vector<int> time(N);
  for(int i = 0; i < N; i++){
    cin >> time.at(i);
  }
  long long ans, sum = T;
  for(int i = 0; i < N-1; i++){
     ans = min(T,time.at(i+1)-time.at(i));
    sum += ans;
  }
  cout << sum << endl;
}
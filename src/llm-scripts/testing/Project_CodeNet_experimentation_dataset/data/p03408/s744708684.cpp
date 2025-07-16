#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  vector<string>s(N);
  for(int i=0; i<N; i++)cin >> s.at(i);
  cin >> M;
  vector<string>t(M);
  for(int i=0; i<M; i++)cin >> t.at(i);
  
  int red =0;
  int blue=0;
  int money = 0;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(s.at(i)==s.at(j))blue++;
    }
    for(int j=0; j<M; j++){
      if(s.at(i)==t.at(j))red++;
    }
    money = max(money, blue-red);
    red=0; blue=0;
  }
  
  cout << money << endl;
}
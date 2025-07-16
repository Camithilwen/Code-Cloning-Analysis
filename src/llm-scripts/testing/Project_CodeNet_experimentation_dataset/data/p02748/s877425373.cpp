#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int>a(A);
  vector<int>b(B);
  vector<vector<int>>xyc(3, vector<int>(M));
  for(int i=0; i<A; i++)cin >> a.at(i);
  for(int i=0; i<B; i++)cin >> b.at(i);
  for(int i=0; i<M; i++){
    for(int j=0; j<3; j++){
      cin >> xyc.at(j).at(i);
    }
  }
  
  int mina = a.at(0);
  int minb = b.at(0);
  for(int i=0; i<A; i++){
    if(mina > a.at(i))mina = a.at(i);
  }
  for(int i=0; i<B; i++){
    if(minb > b.at(i))minb = b.at(i);
  }
  
  int ans = mina + minb;
  
  for(int i=0; i<M; i++){
    int waribiki = a.at(xyc.at(0).at(i)-1) + b.at(xyc.at(1).at(i)-1) - xyc.at(2).at(i);
    if(ans > waribiki)ans = waribiki;
  }
  
  cout << ans << endl;
}
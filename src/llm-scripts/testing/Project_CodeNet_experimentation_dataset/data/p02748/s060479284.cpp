#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,M;
  cin >> A >> B >> M;
  
  vector<int> a(A);
  vector<int> b(B);
  
  for(int i=0;i<A;i++){
    cin >> a[i];
  }
  for(int i=0;i<B;i++){
    cin >> b[i];
  }
  
  vector<vector<int>> ju(M,vector<int>(3));
  
  for(int i=0;i<M;i++){
    for(int j=0;j<3;j++){
      cin >> ju[i][j];
    }
  }
  
  int c=200000;
  
  for(int i=0;i<M;i++){
    c=min(c,a[ju[i][0]-1]+b[ju[i][1]-1]-ju[i][2]);
  }
  
  sort (a.begin(),a.end());
  sort (b.begin(),b.end());
  
  c=min(c,a[0]+b[0]);
  
  cout << c << endl;
}

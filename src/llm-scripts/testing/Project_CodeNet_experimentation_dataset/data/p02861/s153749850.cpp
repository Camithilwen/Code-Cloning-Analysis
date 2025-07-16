#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  double K=0;
  vector<int> X(N),Y(N);
  for(int i=0;i<N;i++){
    cin >> X.at(i) >> Y.at(i);
  }
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      int X2=X.at(i)-X.at(j);
      int Y2=Y.at(i)-Y.at(j);
      K+=sqrt(X2*X2+Y2*Y2);
    }
  }
  cout << fixed << setprecision(10) << 2*K/N << endl;
}
      
      
    
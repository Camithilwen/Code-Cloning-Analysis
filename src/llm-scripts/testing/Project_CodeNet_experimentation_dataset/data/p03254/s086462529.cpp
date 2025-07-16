#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,x;
  cin >> N >> x;
  vector<int> data(N);
  for (int i=0; i<N; i++){
    cin >> data[i];
  }
  sort(data.begin(),data.end());
  for (int i=0; i<N; i++) {
    x = x - data[i];
    if (x == 0) {
      cout << i+1 <<endl;
      return 0;
    }
    if (x < 0){
      cout << i << endl;
      return 0;
    }
    
  }
  cout << N-1 << endl; 
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>vec(5);
  cin >> vec[0] >> vec[1] >> vec[2] >> vec[3] >> vec[4];
  int k;
  cin >> k;
  bool x = true;
  for(int i=0; i<4; i++){
    for(int j=i+1; j<5; j++){
      if(vec[j]-vec[i] > k){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
}

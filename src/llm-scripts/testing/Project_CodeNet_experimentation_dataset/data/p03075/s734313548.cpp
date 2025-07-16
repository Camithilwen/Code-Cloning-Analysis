#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<int> A(5);
  for(int i=0; i<5; i++) cin >> A.at(i);
  int k, ans=0;
  cin >> k;
  
  for(int i=0; i<5; i++) {
    for(int j=i+1; j<5; j++) {
      if(A.at(j) - A.at(i) > k) ans = 1;
    }
  }
  
  if(ans == 0) cout << "Yay!" << endl;
  else cout << ":(" << endl;
  
}
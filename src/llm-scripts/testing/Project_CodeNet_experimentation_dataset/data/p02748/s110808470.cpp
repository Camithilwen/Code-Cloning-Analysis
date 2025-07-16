#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,m;
  cin >> a >> b >> m;
  
  vector<int> refs(a);
  vector<int> renges(b);
  for(int i = 0; i < a; i++) {
     cin >> refs.at(i);
  }
  
  for(int i = 0; i < b; i++) {
     cin >> renges.at(i); 
  }
  
  int ans = refs.at(0) + renges.at(0);
  for(int i = 0; i < m; i++) {
   int aIndex,bIndex,discount;
    cin >> aIndex >> bIndex >> discount;
    int tempAns = refs.at(aIndex - 1) + renges.at(bIndex - 1) - discount;
    
    if(tempAns < ans) {
      ans = tempAns;
    }
  }
  
  std::sort(refs.begin(), refs.end());
  std::sort(renges.begin(), renges.end());
  
  int noDiscount = refs.at(0) + renges.at(0);
  
  if(noDiscount < ans) {
    cout << noDiscount << endl;
  } else {
    cout << ans << endl;
  }
  
  return 0;
}
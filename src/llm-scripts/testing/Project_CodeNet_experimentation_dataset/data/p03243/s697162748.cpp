#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int hund, ten, one, ans;
  for (int i=n ; ; i++){
    hund = i/100;
    ten = (i-hund*100)/10;
    one = i-hund*100-ten*10;
    if (hund == ten && ten == one){
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
}
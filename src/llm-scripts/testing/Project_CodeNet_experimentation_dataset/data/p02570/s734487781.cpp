#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int d, t, s;
  cin >> d >> t >> s;
  
  if(d % s == 0 && d / s <= t){
    cout << "Yes" << endl;
    return 0;
  }else if(d % s != 0 && d / s < t){
    cout << "Yes" << endl;
    return 0;
  }else{
    cout << "No" << endl;
    return 0;
  };
  
  
}
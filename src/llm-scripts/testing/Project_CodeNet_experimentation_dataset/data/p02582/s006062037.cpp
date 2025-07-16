#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string S;
  cin >> S;
  bool p = S.at(0) == 'R';
  bool q = S.at(1) == 'R';
  bool r = S.at(2) == 'R';
  
  if(p && q && r) cout << 3 << endl;
  else if((p && q) || (q && r)) cout << 2 << endl;
  else if(p || q || r) cout << 1 << endl;
  else cout << 0 << endl;
}
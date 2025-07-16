#include<bits/stdc++.h>
using namespace std;

int main() {

  string s;
  int flag = -1, ans = 0;
  int J = 0, O = 0, I = 0;
  cin >> s;

  for(int i=0; i<s.size(); i++) {
    if( flag <= 0 && s[i] == 'J' ) {
      flag = 0;
      J++;
    }
    else if( flag == 0 && s[i] == 'O' ) {
      flag = 1; O++;
    }
    else if( flag == 1 && s[i] == 'O' ) {
      O++;
    }
    else if( flag == 1 && s[i] == 'I' ) {
      flag = 2; 
      if( J >= O ) {
	I++;
	ans = max(1, ans);
      } 
      else {
	flag = -1;
	J = O = I = 0;
      }
    }
    else if( flag == 2 && s[i] == 'I' ) {
      I++; 
      if( I >= O ) {
	ans = max(ans, min(J, min(O, I)));
      }
    }
    else {
      if( s[i] == 'J' ) {
	flag = 0;
	J = 1; O = I = 0;
      }
      else {
	flag = -1;
	J = O = I = 0;
      }
    }
  }

  cout << ans << endl;
}
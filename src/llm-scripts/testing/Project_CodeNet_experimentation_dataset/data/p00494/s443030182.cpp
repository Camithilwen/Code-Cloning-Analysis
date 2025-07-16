#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int JOIlevel(const string &s){
  int J=0,O=0,I=0;
  int res = 0;
  char prec = -1;

  for(int i = 0; i < (int)s.length(); ++i){
    if( s[i] == 'J' && (prec == 'J' || prec == -1 ) ){
      ++J;
      O = 0;
      I = 0;
      prec = s[i];
    }else if( s[i] == 'O' && (prec == 'J' || prec == 'O' ) ){
      ++O;
      prec = s[i];
      I = 0;
      if( O > J ){
        O = 0;
        J = 0;
        prec = -1;
      }
    }else if( s[i] == 'I' && (prec == 'O' || prec == 'I' ) ){
      ++I;
      prec = s[i];
      if( I >= O ){
        res = max(res,min(J,min(O,I)));
      }
    }else{
      J = O = I = 0;
      prec = -1;
      if( s[i] == 'J' ){
        ++J;
        prec = s[i];
      }

    }
    
  }
  return res;
}
int main()
{
  string s;
  while(
        cin >> s){
    cout << JOIlevel(s) << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  string x = "";
  for(int bit = 0; bit < (1 << 3); bit++){
    int seven = s[0] - '0';
    x += s[0];
    for(int i = 1; i < 4; i++){
      if(bit & (1 << (i-1))){
        seven += s[i] - '0';
        x += '+'; 
        x += s[i];
      }else{
        seven -= s[i] - '0';
        x += '-';
        x += s[i];
      }//eles
    }//for
   
    if(seven == 7){
      break;
    }
    seven = 0;
    x = "";
  }//for
  
  cout << x << "=7" << endl;
}
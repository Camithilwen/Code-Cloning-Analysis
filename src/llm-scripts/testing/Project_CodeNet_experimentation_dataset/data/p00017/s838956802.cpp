#include <iostream>
#include <string>
using namespace std;
 
int main(void) {

  string str;
   
  while(getline(cin, str)) {
    while(1) {
      for(int i=0; i<str.length(); i++) {
          if(str[i] != ' ' && str[i] != '.') {
              if(str[i] != 'z'){
                        str[i] += 1;
                    }else{
                        str[i] = 'a';
                    }
          }
      }
      

          if(str.find("the")!=string::npos||str.find("this")!=string::npos||str.find("that")!=string::npos) {
          cout << str << endl;
          break;
      
    }
    }
  }
  return 0;
}
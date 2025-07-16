#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string bstr;

  while (getline(cin, bstr)) {
    int n = 26; 
    while (n--) {
      if (bstr.find("this", 0) != string::npos) {
        break;
      } else if (bstr.find("that", 0) != string::npos) {
        break;
      } else if (bstr.find("the", 0) != string::npos) {
        break;
      }   
      for (int i = 0; i < bstr.size(); i++) {
        if (bstr[i] >= 'a' && bstr[i] <= 'z') {
          if (bstr[i] != 'z')
            bstr[i]++;
          else
            bstr[i] = 'a';
        }
      }   
    }   
    cout << bstr << endl;
  }

  return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  while(getline(cin, str)) {
    int before = 0;
    int now;
    int ans = 0;
    for(int i = 0; i < str.length(); i++) {
      switch(str[i]) {
      case 'I': now = 1; break;
      case 'V': now = 5; break;
      case 'X': now = 10; break;
      case 'L': now = 50; break;
      case 'C': now = 100; break;
      case 'D': now = 500; break;
      case 'M': now = 1000; break;
      }
      if(now > before) {
	ans = ans - before + (now - before);
      } else {
	ans += now;
      }

      before = now;
    }


    cout << ans << endl;
  }
  return 0;
}
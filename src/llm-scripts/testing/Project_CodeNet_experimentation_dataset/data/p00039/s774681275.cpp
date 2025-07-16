#include <iostream>
#include <cstring>
using namespace std;

const char i = 'I', v = 'V', x = 'X', l = 'L', c = 'C', d = 'D', m = 'M';

int number(char s)
{
     switch (s) {
     case i: return 1;
     case v: return 5;
     case x: return 10;
     case l: return 50;
     case c: return 100;
     case d: return 500;
     case m: return 1000;
     }
}

int main()
{
     string str;
     while (cin >> str) {
          int i = 0;
          int ans = 0;
          while (i < str.size()) {
               int tmp = 0;
               char s = str[i];
               while (s == str[i] && i < str.size()) {
                    tmp += number(s);
                    i++;
               }
               if (number(s) < number(str[i])) ans -= tmp;
               else ans += tmp;
          }
          cout << ans << endl;
     }

     return 0;
}
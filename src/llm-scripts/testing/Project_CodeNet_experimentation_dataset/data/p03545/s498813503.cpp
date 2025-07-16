#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int a,b,c,d;
  string s;
  cin >> s;
  
  a = s[0] - '0'; b = s[1] - '0';
  c = s[2] - '0'; d = s[3] - '0';

  if(a+b+c+d == 7) 
    cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl;
  else if(a+b+c-d == 7)
    cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl;
  else if(a+b-c+d == 7)
    cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl;
  else if(a+b-c-d == 7)
    cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl;
  else if(a-b+c+d == 7)
    cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl;
  else if(a-b-c+d == 7)
    cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl;
  else if(a-b+c-d == 7)
    cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl;
  else if(a-b-c-d == 7)
    cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl;
}
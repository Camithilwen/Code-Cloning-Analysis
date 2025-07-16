#include <iostream>
#include <string>

using namespace std;

char decode(char c, int n) {
  if ('a' <= c && c <= 'z') {
    if (c - 'a' >= n) 
      return c-n;
    else 
      return decode('Z', n-(c-'a'+1));
  }
  if ('A' <= c && c <= 'Z') {
    if (c - 'A' >= n)
      return c-n;
    else
      return decode('z', n-(c-'A'+1));
  }
}

int main() {
  int len;
  while(cin >> len, len) {
    int list[len];
    for(int i=0; i<len; i++)
      cin >> list[i];
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
      s[i] = decode(s[i],list[i%len]);
    cout << s << endl;
  }
}
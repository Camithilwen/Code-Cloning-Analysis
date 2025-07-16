#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int ans = 999;
  for(unsigned int i = 0; i < s.length() - 2; ++i)
  {
    int num = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 +(s[i+2] - '0'); 
    ans = min(ans, abs(753 - num));
  }
  
  cout << ans << endl;
}
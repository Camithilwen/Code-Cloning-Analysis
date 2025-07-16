#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int ans = 10000;
  for(int i=0; i<s.size()-2; i++)
  {
    string subs = s.substr(i, 3);
    int a = atoi(subs.c_str());
    ans = min(ans, abs(753 - a));
  }
  
  cout << ans << endl;
  return 0;
}
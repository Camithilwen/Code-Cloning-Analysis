#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  string s = "";
  while(n != 0){
    int r = n%2;
    if (r < 0) r +=2;
    n = (n-r)/(-2);
    s += (char)('0' + r);
  }
  reverse(s.begin(),s.end());
  if (s == "") s = "0";
  cout << s << endl;
  
}

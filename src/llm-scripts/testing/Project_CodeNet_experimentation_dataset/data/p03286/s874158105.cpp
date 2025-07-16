#include <bits/stdc++.h>
using namespace std;

int n, base(-2);
string s;

int main(){
  cin >> n;
  if (n == 0) cout << "0";
  while (n != 0){
    int r = n % base;
    r += (r < 0? 2 : 0);
    s += (n % base == 0 ? "0" : "1");
    n = (n - r) / base;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}

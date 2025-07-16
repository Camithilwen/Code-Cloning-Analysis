#include <bits/stdc++.h>
using namespace std;

string s;

void ans(int a, int64_t b) {  
  //cout << "a:" << a << " b:" << b << " num:" << int64_t(pow(26,a-1)) << endl;
  if(a==1) s.push_back(96+b);
  
  else {
    int64_t num = pow(26,a-1);
    if(b%num!=0) ans(a-1, b%num);
    else ans(a-1, num);
    if(b/num!=26 && b%num==0) s.push_back(96+b/num);
    else if(b/num!=26) s.push_back(97+b/num);
    else s.push_back('z');
  }
}

int main() {
  int64_t n;
  cin >> n;
  
  int digit = 0;
  int64_t sum = 0;
  for(int i=1;;i++) {
    int64_t num = pow(26,i);
    if((n-sum)/num==0) {
      if((n-sum)%num==0) {
        digit = i-1;
        sum -= pow(26,i-1);
      }
      else digit = i;
    }
    if(digit!=0) break;
    sum += num;
  }
  
  ans(digit, n-sum);
  reverse(s.begin(), s.end());
  
  cout << s << endl;
  return 0;
}
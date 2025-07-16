#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  int a,b,c,d,e,f,g,h,i,s;
  a = n/100000000;
  b = n/10000000-10*a;
  c = n/1000000-100*a-10*b;
  d = n/100000-1000*a-100*b-10*c;
  e = n/10000-10000*a-1000*b-100*c-10*d;
  f = n/1000-100000*a-10000*b-1000*c-100*d-10*e;
  g = n/100-1000000*a-100000*b-10000*c-1000*d-100*e-10*f;
  h = n/10-10000000*a-1000000*b-100000*c-10000*d-1000*e-100*f-10*g;
  i = n-100000000*a-10000000*b-1000000*c-100000*d-10000*e-1000*f-100*g-10*h;
  
  s = a+b+c+d+e+f+g+h+i;
  
  if (n/s == (n+s-1)/s) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
}
  
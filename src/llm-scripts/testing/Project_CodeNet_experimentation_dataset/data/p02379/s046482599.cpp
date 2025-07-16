#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
  long double n,m,x,y,w,z;
  cin >> x>>y>>w>>z;
  n = x-w;
  m = y-z;
  
  cout << setprecision(10) <<sqrt(n*n+m*m) << endl;
    return 0;
}


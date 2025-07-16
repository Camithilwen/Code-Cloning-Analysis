#include <string>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b;
  cin >> a >> b;
  int aa = 0;
  int bb = 0;
  int cc = 0;
  int dd = 0;
  int ee = 0;
  int ff = 0;
  
  if (a == 1)
    ee = 300000;
  else if (a == 2)
    aa = 200000;
  else if (a == 3)
    bb = 100000;
   if (b == 1)
    ff = 300000;
   else if (b == 2)
    cc = 200000;
   else if (b == 3)
    dd = 100000;
  
  if (a == 1 && b == 1)
    cout << "1000000";
  else
    cout << aa + bb + cc + dd + ee + ff;
}
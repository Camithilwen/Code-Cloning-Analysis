#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  double x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout.precision(9);
  cout.setf(ios::fixed);
  cout  << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << endl;
  return 0;
}
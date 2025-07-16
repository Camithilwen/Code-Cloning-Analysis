#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double distance(double, double, double, double);

int main(){
  double x1 ,y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << fixed << setprecision(12);
  cout << distance(x1, y1, x2, y2) << endl;
}

double distance(double x1, double y1, double x2, double y2){
  double sumsq;
  sumsq = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  return pow(sumsq, 0.5);
}


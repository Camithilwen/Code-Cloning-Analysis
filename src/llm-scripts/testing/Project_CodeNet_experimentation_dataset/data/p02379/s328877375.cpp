#include<iostream>
#include<cmath>
using namespace std;

int main(){
  double x1, x2, y1, y2, dis;

  cin >> x1 >> y1 >> x2 >> y2;
  dis = sqrt(pow(x2 - x1,2.0) + pow(y2 - y1,2.0));
  cout << fixed << dis <<endl;
  return 0;
}
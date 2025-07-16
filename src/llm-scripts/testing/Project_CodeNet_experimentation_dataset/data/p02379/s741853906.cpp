#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>

using namespace std;
int main() {
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  printf("%.7f \n", sqrt(pow((x2-x1), (double)2) + pow((y2-y1), (double)2)));

}
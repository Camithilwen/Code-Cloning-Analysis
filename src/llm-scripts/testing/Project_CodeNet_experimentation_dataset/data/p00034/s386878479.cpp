#include <iostream>
#include <cstdio>

using namespace std;

double l[10];
double v1, v2;

int main()
{
  while (scanf("%lf", &l[0]) == 1) {
    int sum = l[0];
    for (int i = 1; i < 10; i++) {
      scanf(",%lf", &l[i]);
      sum += l[i];
    }
    scanf(",%lf,%lf", &v1, &v2);
    
    double x = (sum * v1) / (v1 + v2);

    int c;
    for (c = 0; x > 0; c++) {
      x -= l[c];
    }
    
    printf("%d\n", c);
  }
  return 0;
}
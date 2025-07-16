#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

int main()
{
  double x1, y1, x2, y2;
  fscanf(stdin, "%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  fprintf(stdout, "%.9f\n", hypot(x1 - x2, y1 - y2));
  return 0;
}
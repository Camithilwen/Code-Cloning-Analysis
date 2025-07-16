#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  double d[10], v1, v2;
  vector<int> result;
  while (scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,\n",
               d, d+1, d+2, d+3, d+4, d+5, d+6, d+7, d+8, d+9, &v1, &v2) != EOF) {
    double hoge = 0;
    for (int i = 0; i < 10; i++)
      hoge += d[i];
    hoge /= v1 + v2;
    hoge *= v1;
    for (int i = 0; i < 10; i++) {
      hoge -= d[i];
      if (hoge <= 0) {
        result.push_back(i+1);
        break;
      }
    }
  }

  for (int i = 0; i < result.size(); i++)
    cout << result[i] << endl;
  return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {

   double x[2]{}, y[2]{}, distance{};

   cin >> x[0] >> y[0] >> x[1] >> y[1];

   distance = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
   cout << fixed << distance;

   return 0;

}
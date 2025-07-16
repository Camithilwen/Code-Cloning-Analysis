#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int P[2];
  for(int i = 0; i < 2; i++){
    vector<int> point(10);
    for(int j = 0; j < 10; j++){
      cin >> point[j];
    }
    sort(point.rbegin(), point.rend());
     P[i] = point[0] + point[1] + point[2];
  }
  cout << P[0] << " " << P[1] << endl;
}
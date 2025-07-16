#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int rating, next_rating, performance;
  cin >> rating >> next_rating;
  
  performance = 2 * next_rating - rating;
  cout << performance << endl;
}
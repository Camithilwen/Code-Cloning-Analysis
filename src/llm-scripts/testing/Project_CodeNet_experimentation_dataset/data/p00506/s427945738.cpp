#include <iostream>
using namespace std;

int main()
{
  int n;
  int a, b, c;

  cin >> n;
  if (n == 2){
    cin >> a >> b;
    if (a > b){
      int c = a;
      a = b;
      b = c;
    }
    for (int i = 1; i <= a; i++){
      if (a % i == 0 && b % i == 0){
        cout << i << "\n";
      }
    }
    return 0;
  }

  cin >> a >> b >> c;
  if (c < b){
    int d = c;
    c = b;
    b = d;
  }
  if (b < a){
    int d = a;
    a = b;
    b = d;
  }
  if (c < b){
    int d = c;
    c = b;
    b = d;
  }
  for (int i = 1; i <= a; i++){
    if (a % i == 0 && b % i == 0 && c % i == 0){
      cout << i << endl;
    }
  }

  return 0;
}